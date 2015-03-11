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
 *     $File name :  Periodictester.h
 *     $Auther    :  Zhuo Yuzhen
 *     $Date      :  11 Mar, 2015
 *  ------------------------------------------------------------------------- */

#ifndef PERIODICTESTER_H_
#define PERIODICTESTER_H_

#include "Periodicrunner.h"
#include <boost/chrono.hpp>




template <typename Duration>
class Periodictester: public Periodicrunner <Duration> {
public:
    Periodictester():
        Periodicrunner<Duration>::Periodicrunner(3){
            // TODO Auto-generated constructor stub

        };


    virtual ~Periodictester(){

    }


    void cycleexec(void){
        std::cout<< "Derived class cycle execution"<<std::endl;
    };
};



#endif /* PERIODICTESTER_H_ */
