/* 
 * File:   mechanic.h
 * Author: gaming
 *
 * Created on July 2, 2014, 12:19 PM
 */

#ifndef MECHANIC_H
#define	MECHANIC_H
#include "time.h"
#include "garage.h"

typedef struct {
    short unsigned int nrOfGarage;
    time startWork;
    time finishWork;

} tSchedule;

typedef struct {
    char *name;
    unsigned int nr;
    enumSpeciality speciality;
    Date dateOfBirth;
    tSchedule *shift;
    short unsigned int nrOfShifts;
    //time startWorkHour;
    //time stopWorkHour;
} tMechanic;


tMechanic* InsertMechanic(tMechanic*,unsigned int*, tGarage*,short unsigned int);
bool IsNrHiggerThanZeroOrEqual(short unsigned int);
bool IsShiftTimeValid(char shiftTime[], short unsigned int*, short unsigned int*);
short unsigned int ConcateShiftTime(char, char);
bool IsShiftStartTimeAndEndTimeValid (time, time);
bool ShiftIsAvaiable(tMechanic*, unsigned int, short unsigned int,time, time);

char *GetMechanicName();
Date GetMechanicBirthDay();
 short unsigned int GetMechanicSpeciality();
 short unsigned int GetMechanicNrOfShifts ();
tMechanic *GetMechanicShift(tMechanic *mechanic, unsigned int currentNrOfMechanics, unsigned int mechanicNrToGiveShift, 
        tGarage *garage, short unsigned int currentNrOfGarages);
void ShowAllMechanic(tMechanic *mechanic, int currentNrOfMechanics);
void ShowMechanic(tMechanic *mechanic, unsigned int i);
int SearchMechanic(tMechanic *mechanic, unsigned int numMechanic,unsigned int *fID);
void material_sort(tMechanic* mechanic, unsigned int numMechanic);
tMechanic *mechanic_add(tMechanic *mechanic, unsigned int *numMechanic,tMechanic elementToAdd, bool isToOrder);
unsigned int *mechanic_addID(unsigned int *fID, unsigned int numMechanic,unsigned int elementToAdd);
void mechanic_outputSearch(tMechanic mechanic, unsigned int id);
void mechanic_sort(tMechanic* mechanic, unsigned int numMechanic);
void ListMechanicEditFields();
int string_lentgh(char* str);
tMechanic *EditMechanic(tMechanic *mechanic, int currentNrOfMechanics, tGarage *garage, short unsigned int currentNrOfGarages);
short unsigned int *CheckGarageAvaiableForMechanic (short unsigned int mechanicSpeciality, 
        tGarage *garage, short unsigned int currentNrOfGarages, short unsigned int *nrOfGaragesAvaiable);

void ListShifs(tSchedule *shift, short unsigned int currentNrOfShifts);
tSchedule *DeleteShift(tSchedule *shift, short unsigned int currentNrOfShifts);
tMechanic *ShiftMenu(tMechanic *mechanic, unsigned int currentNrOfMechanics,
        unsigned int mechanicNrToGiveShift, tGarage *garage, short unsigned int currentNrOfGarages);
#endif	/* MECHANIC_H */
