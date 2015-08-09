/*!
@file
Forward declares `boost::hana::empty`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_FWD_EMPTY_HPP
#define BOOST_HANA_FWD_EMPTY_HPP

#include <boost/hana/core/when.hpp>


namespace boost { namespace hana {
    //! Identity of the monadic combination `concat`.
    //! @relates MonadPlus
    //!
    //! Signature
    //! ---------
    //! Given a MonadPlus `M`, the signature is
    //! @f$ \mathtt{empty}_M : \emptyset \to M(T) @f$.
    //!
    //! @tparam M
    //! The data type of the monadic structure to return. This must be
    //! a model of the MonadPlus concept.
    //!
    //!
    //! Example
    //! -------
    //! @include example/empty.cpp
#ifdef BOOST_HANA_DOXYGEN_INVOKED
    template <typename M>
    constexpr auto empty = []() {
        return tag-dispatched;
    };
#else
    template <typename M, typename = void>
    struct empty_impl : empty_impl<M, when<true>> { };

    template <typename M>
    struct empty_t;

    template <typename M>
    constexpr empty_t<M> empty{};
#endif
}} // end namespace boost::hana

#endif // !BOOST_HANA_FWD_EMPTY_HPP
