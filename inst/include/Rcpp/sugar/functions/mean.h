// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 8 -*-
//
// mean.h: Rcpp R/C++ interface class library -- mean
//
// Copyright (C) 2011 - 2014  Dirk Eddelbuettel and Romain Francois
//
// This file is part of Rcpp.
//
// Rcpp is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// Rcpp is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Rcpp.  If not, see <http://www.gnu.org/licenses/>.

#ifndef Rcpp__sugar__mean_h
#define Rcpp__sugar__mean_h

namespace Rcpp{
namespace sugar{

template <int RTYPE, bool NA, typename T>
class Mean : public Lazy<typename Rcpp::traits::storage_type<RTYPE>::type, Mean<RTYPE,NA,T> > {
public:
    typedef typename Rcpp::VectorBase<RTYPE,NA,T> VEC_TYPE;
    typedef typename Rcpp::traits::storage_type<RTYPE>::type STORAGE;
    typedef Rcpp::Vector<RTYPE> VECTOR;

    Mean(const VEC_TYPE& object_) : object(object_) {}

    STORAGE get() const {
        VECTOR input = object;
        int n = input.size();           // double pass (as in summary.c)
        long double s = std::accumulate(input.begin(), input.end(), 0.0L);
        s /= n;
        if (R_FINITE((double)s)) {
            long double t = 0.0;
            for (int i = 0; i < n; i++) {
                t += input[i] - s;
            }
            s += t/n;
        }
        return (double)s ;
    }
private:
    const VEC_TYPE& object ;
};

} // sugar

template <bool NA, typename T>
inline sugar::Mean<REALSXP,NA,T> mean(const VectorBase<REALSXP,NA,T>& t) {
    return sugar::Mean<REALSXP,NA,T>(t);
}

template <bool NA, typename T>
inline sugar::Mean<INTSXP,NA,T> mean(const VectorBase<INTSXP,NA,T>& t) {
    return sugar::Mean<INTSXP,NA,T>(t);
}

} // Rcpp
#endif


