// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; tab-width: 4 -*-
//
// config.h: Rcpp R/C++ interface class library -- Rcpp configuration of optional features
//
// Copyright (C) 2010 - 2012  Dirk Eddelbuettel and Romain Francois
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

#ifndef RCPP__CONFIG_H
#define RCPP__CONFIG_H

#ifdef __GNUC__
  // from http://sourceforge.net/apps/mediawiki/predef/index.php?title=Operating_Systems#MacOS
  #ifdef __APPLE__ 
    #include <Availability.h>
    #ifndef __MAC_10_8
        #define RCPP_HAS_DEMANGLING
    #endif
  #else
      #define RCPP_HAS_DEMANGLING
  #endif
#endif

#define Rcpp_Version(v,p,s) (((v) * 65536) + ((p) * 256) + (s))
#define RCPP_VERSION Rcpp_Version(0,10,1)
                                                                                                                
#endif

