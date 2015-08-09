/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/assert.hpp>
#include <boost/hana/empty.hpp>
#include <boost/hana/optional.hpp>
#include <boost/hana/tuple.hpp>
namespace hana = boost::hana;


BOOST_HANA_CONSTANT_CHECK(hana::empty<hana::Tuple>() == hana::make_tuple());
BOOST_HANA_CONSTANT_CHECK(hana::empty<hana::Optional>() == hana::nothing);

int main() { }
