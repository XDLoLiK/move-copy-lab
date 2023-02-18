#ifndef MOVE_HPP
#define MOVE_HPP

#include "remove_reference.hpp"

namespace stdlike {

template <typename T>
typename remove_reference<T>::type&& move(T&& arg) {
    return static_cast<typename remove_reference<T>::type&&>(arg);
}

}


#endif /* MOVE_HPP */
