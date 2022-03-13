/*
 * UTILS.h
 *
 * Created: 12-Mar-22 12:28:48 PM
 *  Author: lenovo
 */ 


#ifndef UTILS_H_
#define UTILS_H_


#define SET_BIT(REG,BIT)  REG=REG |(1<<BIT)
#define CLR_BIT(REG,BIT)  REG=REG &~(1<<BIT)
#define TOG_BIT(REG,BIT)  REG=REG ^(1<<BIT)
#define GET_BIT(REG,BIT)  ((REG>>BIT)&1)
#define ASSIGN_REG(REG,VALUE)   (REG=VALUE)


#endif /* UTILS_H_ */