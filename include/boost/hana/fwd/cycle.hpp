/*!
@file
Forward declares `boost::hana::cycle`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_FWD_CYCLE_HPP
#define BOOST_HANA_FWD_CYCLE_HPP

#include <boost/hana/core/when.hpp>


namespace boost { namespace hana {
    //! Combine a monadic structure with itself `n` times.
    //! @relates MonadPlus
    //!
    //! Given a monadic structure `xs` and a non-negative number `n`,
    //! `cycle` returns a new monadic structure which is the result of
    //! combining `xs` with itself `n` times using the `concat` operation.
    //! In other words,
    //! @code
    //!     cycle(xs, n) == concat(xs, concat(xs, ... concat(xs, xs)))
    //!                                       // ^^^^^ n times total
    //! @endcode
    //!
    //! Also note that since `concat` is required to be associative, we
    //! could also have written
    //! @code
    //!     cycle(xs, n) == concat(concat(... concat(xs, xs), xs), xs)
    //!                               // ^^^^^ n times total
    //! @endcode
    //!
    //! If `n` is zero, then the identity of `concat`, `empty`, is returned.
    //! In the case of sequences, this boils down to returning a sequence
    //! containing `n` copies of itself; for other models it might differ.
    //!
    //!
    //! Signature
    //! ---------
    //! Given a Constant `C` and a MonadPlus `M`, the signature is
    //! @f$ \mathrm{cycle} : M(T) \times C \to M(T) @f$.
    //!
    //! @param xs
    //! A monadic structure to combine with itself a certain number of times.
    //!
    //! @param n
    //! A non-negative `Constant` of an unsigned integral type representing
    //! the number of times to combine the monadic structure with itself.
    //! If `n` is zero, `cycle` returns `empty`.
    //!
    //!
    //! Example
    //! -------
    //! @include example/cycle.cpp
#ifdef BOOST_HANA_DOXYGEN_INVOKED
    constexpr auto cycle = [](auto&& xs, auto&& n) {
        return tag-dispatched;
    };
#else
    template <typename M, typename = void>
    struct cycle_impl : cycle_impl<M, when<true>> { };

    struct cycle_t {
        template <typename Xs, typename N>
        constexpr auto operator()(Xs&& xs, N&& n) const;
    };

    constexpr cycle_t cycle{};
#endif
}} // end namespace boost::hana

#endif // !BOOST_HANA_FWD_CYCLE_HPP
