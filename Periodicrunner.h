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
 *     $File name :  Periodicrunner.h
 *     $Auther    :  Zhuo Yuzhen
 *     $Date      :  11 Mar, 2015
 *  ------------------------------------------------------------------------- */

#ifndef PERIODICRUNNER_H_
#define PERIODICRUNNER_H_

#include <cstdint>
#include <boost/chrono.hpp>
#include <boost/thread.hpp>

using namespace boost::chrono;

template <typename Duration>
class Periodicrunner {
public:
    Periodicrunner(uint16_t p):
        errorstatus(0), period(p){
    };


    virtual ~Periodicrunner(){

    }


    void run(void){
        next_cycle_start_time = time_point_cast<Duration>(system_clock::now());

        while(true){
            this_cycle_start_time = next_cycle_start_time;
            try {
                next_cycle_start_time = this_cycle_start_time + Duration(period);
                cycleexec();
            }
            catch (boost::system::system_error& e) {
                std::cerr<< e.what() <<std::endl;
            }
            catch (...){
                std::cerr<< "Periodic runner cycle execution error" <<std::endl;
            }
            boost::this_thread::sleep_until(next_cycle_start_time);
        }
    }



    virtual void cycleexec(void){
        std::cout<< "Base class execution" <<std::endl;
    }



    void setPeriod(uint16_t newperiod){
        period = newperiod;
    }


    uint16_t getPeriod(void){
        return period;
    }


    uint8_t geterrorstatus(void){
        return errorstatus;
    }


    void seterrorstatus(uint8_t error) {
        errorstatus = error;
    }


private:
    uint8_t errorstatus;
    uint16_t period;
    time_point<system_clock,Duration> this_cycle_start_time;
    time_point<system_clock,Duration> next_cycle_start_time;
};

#endif /* PERIODICRUNNER_H_ */
