#ifndef OPTIONAL_H
#define OPTIONAL_H

#include <utility>
#include <type_traits>
#include <iostream>

namespace experimental {
  
  template <typename T> class Optional
    {
      /**
       * \brief The internal storage of size T and
       * properly aligned on T.
       */
      typename std::aligned_storage<sizeof(T), alignof(T)>::type storage;

      /**
       * \brief Indicates whether the storage is
       * initialized.
       */
      bool mStored;
      
    public:
      
      /**
       * \brief Object constructor.
       */
      Optional() : mStored(false) {}
      
      /**
       * \brief Object constructor.
       * \param v the object to store.
       */
      Optional(const T& v) : mStored(true) {
        new (&storage) T(v);
      }
      
      /**
       * \brief Object copy constructor.
       */
      Optional(const Optional<T>& other) {
        mStored = other.mStored;
        if (mStored) {
          new (&storage) T(other.get());
        }
      }
      
      /**
       * \brief Assignment operator.
       */
      Optional& operator=(Optional<T> other) {
        std::swap(mStored, other.mStored);
        std::swap(storage, other.storage);
        return (*this);
      }
      
      /**
       * \brief Object destructor.
       */
      ~Optional() {
        if (mStored) {
          get().~T();
        }
      }
            
      /**
       * \return the currently stored optional value.
       * \note This is the const version.
       */
      T const& get() const {
        return *static_cast<const T*>(static_cast<const void*>(&storage));
      }
      
      /**
       * \return the currently stored optional value.
       * \note This is the non-const version.
       */
      T& get() {
        return *static_cast<T*>(static_cast<void*>(&storage));
      }

      /**
       * \return the currently stored session token if any,
       * an empty string otherwise.
       */
      explicit operator bool() const {
        return (mStored);
      }
    };
};

#endif
