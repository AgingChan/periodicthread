/*  -------------------------------------------------------------------------
 *  Copyright (C) <2015> RFCOM Technologies Pte. Ltd.
 *  All rights reserved.
 *  -------------------------------------------------------------------------
 *  This document contains proprietary information belonging to RFCOM
 *  Technologies. Passing on and copying of this document, use and
 *  communication of its contents is not permitted without prior written
 *  authorization.
 *  -------------------------------------------------------------------------
 *  File Brief:
 *     
 *
 *  -------------------------------------------------------------------------
 *  Revision Information:
 *     $File name :  test.cpp
 *     $Auther    :  Zhuo Yuzhen
 *     $Date      :  6 Mar, 2015
 *  ------------------------------------------------------------------------- */




/*  -------------------------------------------------------------------------
 *  Copyright (C) <2015> RFCOM Technologies Pte. Ltd.
 *  All rights reserved.
 *  -------------------------------------------------------------------------
 *  This document contains proprietary information belonging to RFCOM
 *  Technologies. Passing on and copying of this document, use and
 *  communication of its contents is not permitted without prior written
 *  authorization.
 *  -------------------------------------------------------------------------
 *  File Brief:
 *
 *
 *  -------------------------------------------------------------------------
 *  Revision Information:
 *     $File name :  test.cpp
 *     $Auther    :  Zhuo Yuzhen
 *     $Date      :  6 Mar, 2015
 *  ------------------------------------------------------------------------- */


#include <iostream>
#include <string>
#include <cstdlib>
#include <regex>
#include <ctime>
#include <boost/chrono.hpp>
#include <boost/thread.hpp>
#include "Periodictester.h"

int main (){

    Periodicrunner<boost::chrono::seconds> *tester = new Periodictester<boost::chrono::seconds>();

    boost::thread* test_thread = new boost::thread(boost::bind(&Periodicrunner<boost::chrono::seconds>::run, tester));

    test_thread->join();


}

