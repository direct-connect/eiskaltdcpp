/*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "stdinc.h"

#include "SSL.h"
#include "Util.h"

namespace dcpp {
namespace ssl {

vector<uint8_t> X509_digest(::X509* x509, const ::EVP_MD* md) {
    unsigned int n;
    unsigned char buf[EVP_MAX_MD_SIZE];

    if (!X509_digest(x509, md, buf, &n)) {
        return vector<uint8_t>(); // Throw instead?
    }
    return vector<uint8_t>(buf, buf+n);
}

}
}
