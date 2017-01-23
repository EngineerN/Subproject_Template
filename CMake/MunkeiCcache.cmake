# The MIT License (MIT)
#
# Copyright (c) 2016-2017 Theo Willows
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

cmake_minimum_required( VERSION 3.0.0 )

include( CMakeParseArguments )

function( ccache )
  set( options
    REQUIRED
    )
  set( oneValueArgs
    EXECUTABLE
    )
  set( multiValueArgs )
  cmake_parse_arguments( ARGS
    "${options}"
    "${oneValueArgs}"
    "${multiValueArgs}"
    ${ARGN}
    )

  if( DEFINED ARGS_EXECUTABLE )
    set( ccache ${ARGS_EXECUTABLE} )
  else( DEFINED ARGS_EXECUTABLE )
    find_program( ccache ccache )
  endif( DEFINED ARGS_EXECUTABLE )

  if( ccache )
    message( STATUS "[MunkeiCcache] Using ccache: ${ccache}" )
    set_property( GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${ccache} )
    set_property( GLOBAL PROPERTY RULE_LAUNCH_LINK    ${ccache} )
  elseif( ARGS_REQUIRED )
    message( FATAL_ERROR "[MunkeiCcache] Could not find ccache" )
  else()
    message( STATUS "[MunkeiCcache] Skipping ccache" )
  endif()
endfunction( ccache )
