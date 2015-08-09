/*
@copyright Louis Dionne 2015
Distributed under the Boost Software License, Version 1.0.
(See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
 */

#include <boost/hana/duplicate.hpp>
#include <boost/hana/extract.hpp>
#include <boost/hana/lazy.hpp>
namespace hana = boost::hana;


int main() {
    constexpr auto very_lazy = hana::duplicate(hana::lazy(3));
    static_assert(hana::extract(hana::extract(very_lazy)) == 3, "");
}
