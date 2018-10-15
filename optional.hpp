#ifndef OPTIONAL_H_
#define OPTIONAL_H_

#include <utility>
#include <type_traits>

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
       * \constructor.
       * \param v the object to store.
       */
      Optional(const T& v) : mStored(true) {
        new (&storage) T(v);
      }

      /**
       * \brief Copy constructor.
       */
      Optional(const Optional<T>& other)
        : mStored(other.mStored) {
        if (mStored) {
          new (&storage) T(other.get());
        }
      }

      /**
       * \brief Move constructor.
       */
      Optional(Optional<T>&& other)
        : mStored(other.mStored) {
        if (mStored) {
          new (&storage) T(std::move(other.get()));
        }
      }

      /**                                                                                                                                                                                       
       * \brief Assignment operator.                                                                                                                                                            
       */
      Optional& operator=(const Optional<T>& other) {
        if (this != &other) {
          return (*this);
        }
        if (mStored = other.mStored) {
          new (&storage) T(other.get());
        }
        return (*this);
      }

      /**                                                                                                                                                                                       
       * \brief Move assignment operator.                                                                                                                                                       
       */
      Optional& operator=(Optional<T>&& other) {
        if (this != &other) {
          return (*this);
        }
        if (mStored = other.mStored) {
          new (&storage) T(std::move(other.get()));
        }
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

#endif // OPTIONAL_H_
