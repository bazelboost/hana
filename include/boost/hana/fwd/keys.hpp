/*!
@file
Forward declares `boost::hana::keys`.

@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_HANA_FWD_KEYS_HPP
#define BOOST_HANA_FWD_KEYS_HPP

#include <boost/hana/core/when.hpp>


namespace boost { namespace hana {
    //! Returns the keys of a data structure.
    //!
    //! This function is not associated to any concept right now. As such,
    //! it can't be described generally and the documentation for specific
    //! implementations should be consulted instead.
#ifdef BOOST_HANA_DOXYGEN_INVOKED
    constexpr auto keys = [](auto&& xs) {
        return tag-dispatched;
    };
#else
    template <typename T, typename = void>
    struct keys_impl : keys_impl<T, when<true>> { };

    struct keys_t {
        template <typename Map>
        constexpr auto operator()(Map&& map) const;
    };

    constexpr keys_t keys{};
#endif

    //! Returns a `Sequence` containing the name of the members of
    //! the data structure.
    //! @relates Struct
    //!
    //! Given a `Struct` object, `keys` returns a `Sequence` containing the
    //! name of all the members of the `Struct`, in the same order as they
    //! appear in the `accessors` sequence.
    //!
    //!
    //! Example
    //! -------
    //! @include example/struct/keys.cpp
#ifdef BOOST_HANA_DOXYGEN_INVOKED
    constexpr auto keys = [](auto&& object) {
        return unspecified-type;
    };
#endif
}} // end namespace boost::hana

#endif // !BOOST_HANA_FWD_KEYS_HPP
