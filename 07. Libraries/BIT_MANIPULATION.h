/******************************************************************************
 * FILE: BIT_MANIPULATION.h
 * DESCRIPTION:  C header file contains declration and documentation
 *               for macros like function that performs bitwise operations
 *               on registers
 *
 *              Bit Masks:
 *                  --> BIT_GET
 *                  --> BIT_SET
 *                  --> BIT_CLEAR
 *                  --> BIT_TOGGLE
 *
 *              Nibble Masks:
 *                  --> LOW_NIBBLE_GET
 *                  --> LOW_NIBBLE_SET
 *                  --> LOW_NIBBLE_CLEAR
 *
 *                  --> HIGH_NIBBLE_GET
 *                  --> HIGH_NIBBLE_SET
 *                  --> HIGH_NIBBLE_CLEAR
 *
 *              Register Masks:
 *                  --> REG_FLIP_BITS (One's Complement)
 *                  --> REG_TOWS_COMPLEMENT
 *                  --> REG_CLEAR
 *
 *                  --> REG_NUMBER_OF_BITS
 *                  --> REG_MOST_SIGNIFICANT_BIT
 *                  --> REG_LEAST_SIGNIFICANT_BIT
 *
 *                  --> REG_IS_EVEN
 *                  --> REG_IS_ODD
 *
 * AUTHOR: Ahmed Harbi
 * DATE: Jan 2022
 *****************************************************************************/

#ifndef _BIT_MANIPULATION_H_
#define _BIT_MANIPULATION_H_

#include <stdio.h>
#include <stdlib.h>

#include "ARRAY.h"
#include "MATH.h"
#include "SORTING.h"
#include "STRINGS.h"

#define BYTE 8
#define NIBBLE 4

/* ========================================================================================================== */

/* =============== Bit Masks =================== */

/******************************************************************************
 * MACRO: BIT_GET
 * DESCRIPTION:
 *          This macro takes a register value and position of bit to be checked,
 *          and return 1 if this bit is high, or 0 if this bit is low.
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 *      - BIT_NUM: Position of the bit to be checked indexed from 0
 ******************************************************************************/

#define BIT_GET(REG, BIT_NUM) (((REG) >> (BIT_NUM)) & 1)

/******************************************************************************
 * MACRO: BIT_SET
 * DESCRIPTION:
 *          This macro takes a register value and position of bit to be setted,
 *          and set this bit to 1.
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 *      - BIT_NUM: Position of the bit to be checked indexed from 0
 ******************************************************************************/

#define BIT_SET(REG, BIT_NUM) ((REG) |= (1 << (BIT_NUM)))

/******************************************************************************
 * MACRO: BIT_CLEAR
 * DESCRIPTION:
 *          This macro takes a register value and position of bit to be cleared,
 *          and set this bit to 0.
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 *      - BIT_NUM: Position of the bit to be checked indexed from 0
 ******************************************************************************/

#define BIT_CLEAR(REG, BIT_NUM) ((REG) &= (~(1 << (BIT_NUM))))

/******************************************************************************
 * MACRO: BIT_TOGGLE
 * DESCRIPTION:
 *          This macro takes a register value and position of bit to be toggled,
 *          and toggle this bit. (1 --> 0) and (0 --> 1)
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 *      - BIT_NUM: Position of the bit to be checked indexed from 0
 ******************************************************************************/

#define BIT_TOGGLE(REG, BIT_NUM) ((REG) ^= (1 << (BIT_NUM)))

/* ========================================================================================================== */

/* =============== Nibble Masks =================== */

/******************************************************************************
 * MACRO: LOW_NIBBLE_GET
 * DESCRIPTION:
 *          This macro takes a register value, and return the value of the
 *          first four bits in this register.
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 ******************************************************************************/

#define LOW_NIBBLE_GET(REG) (((REG)&0x0FU))

/******************************************************************************
 * MACRO: LOW_NIBBLE_SET
 * DESCRIPTION:
 *          This macro takes a register value, and set the value of the
 *          first four bits in this register to Ones.
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 ******************************************************************************/

#define LOW_NIBBLE_SET(REG) ((REG) |= 0x0FU)

/******************************************************************************
 * MACRO: LOW_NIBBLE_CLEAR
 * DESCRIPTION:
 *          This macro takes a register value, and set the value of the
 *          first four bits in this register to zeros.
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 ******************************************************************************/

#define LOW_NIBBLE_CLEAR(REG) ((REG) &= 0xF0U)

/******************************************************************************
 * MACRO: HIGH_NIBBLE_GET
 * DESCRIPTION:
 *          This macro takes a register value, and return the value of the
 *          last four bits in this register.
 *
 * PARAMETERS:
 *      - REG: Numerical value of 1 byte represents the number
 ******************************************************************************/

#define HIGH_NIBBLE_GET(REG) (((REG)&0xF0U) >> NIBBLE)

/******************************************************************************
 * MACRO: HIGH_NIBBLE_SET
 * DESCRIPTION:
 *          This macro takes a register value, and set the value of the
 *          last four bits in this register to Ones.
 *
 * PARAMETERS:
 *      - REG: Numerical value of 1 byte represents the number
 ******************************************************************************/

#define HIGH_NIBBLE_SET(REG) ((REG) |= 0xF0U)

/******************************************************************************
 * MACRO: HIGH_NIBBLE_CLEAR
 * DESCRIPTION:
 *          This macro takes a register value, and set the value of the
 *          last four bits in this register to zeros.
 *
 * PARAMETERS:
 *      - REG: Numerical value of 1 byte represents the number
 ******************************************************************************/

#define HIGH_NIBBLE_CLEAR(REG) ((REG) &= 0x0FU)

/* ========================================================================================================== */

/* =============== Register Masks =================== */

/******************************************************************************
 * MACRO: REG_FLIP_BITS
 * DESCRIPTION:
 *          This macro takes a register value, and toggle all bits of this
 *          register.
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 ******************************************************************************/

#define REG_FLIP_BITS(REG) (~(REG))

/******************************************************************************
 * MACRO: REG_TOWS_COMPLEMENT
 * DESCRIPTION:
 *          This macro takes a register value, and return its negative value.
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 ******************************************************************************/

#define REG_TOWS_COMPLEMENT(REG) (REG_FLIP_BITS((REG)) + 1)

/******************************************************************************
 * MACRO: REG_CLEAR
 * DESCRIPTION:
 *          This macro takes a register value, and set all of its bits to zero.
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 ******************************************************************************/

#define REG_CLEAR(REG) ((REG) ^= (REG))

/******************************************************************************
 * MACRO: REG_NUMBER_OF_BITS
 * DESCRIPTION:
 *          This macro takes a register value, and return the number of its bits.
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 ******************************************************************************/

#define REG_NUMBER_OF_BITS(REG) (sizeof((REG)) * BYTE)

/******************************************************************************
 * MACRO: REG_MOST_SIGNIFICANT_BIT
 * DESCRIPTION:
 *          This macro takes a register value, and return the value of its
 *          most significant bit.
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 ******************************************************************************/

#define REG_MOST_SIGNIFICANT_BIT(REG) (BIT_GET((REG), (REG_NUMBER_OF_BITS((REG)) - 1)))

/******************************************************************************
 * MACRO: REG_LEAST_SIGNIFICANT_BIT
 * DESCRIPTION:
 *          This macro takes a register value, and return the value of its
 *          least significant bit.
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 ******************************************************************************/

#define REG_LEAST_SIGNIFICANT_BIT(REG) (BIT_GET((REG), 0))

/******************************************************************************
 * MACRO: REG_IS_EVEN_BITWISE
 * DESCRIPTION:
 *          This macro takes a register value, and return 1 if the value
 *          is even, and 0 if the value is odd.
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 ******************************************************************************/

#define REG_IS_EVEN_BITWISE(REG) (LEAST_SIGNIFICANT_BIT((REG)) ? 0 : 1)

/******************************************************************************
 * MACRO: REG_IS_ODD_BITWISE
 * DESCRIPTION:
 *          This macro takes a register value, and return 1 if the value
 *          is odd, and 0 if the value is even.
 *
 * PARAMETERS:
 *      - REG: Numerical value of the number
 ******************************************************************************/

#define REG_IS_ODD_BITWISE(REG) (LEAST_SIGNIFICANT_BIT((REG)) ? 1 : 0)

#endif /* _BIT_MANIPULATION_H_ */