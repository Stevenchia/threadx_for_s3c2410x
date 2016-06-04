;/**************************************************************************/ 
;/*                                                                        */ 
;/*      only for 32bit mode and dosn't support interrupt nesting          */
;/*                                                                        */  
;/* File name:               threadX_cpu.s								   */
;/* Last modified Date:      2008-03-28									   */
;/* Last Version:            0.01										   */
;/* Descriptions:            asm file for armtarget						   */
;/* QQ:                      307102293									   */
;/* ENAIL:                   wodexinxiang1949@163.com                      */
;/*                                                                        */
;/**************************************************************************/

;/* mode config  */
Mode_USR            EQU         0x10                                   ;/* �û�ģʽ                     */
Mode_FIQ            EQU         0x11                                   ;/* ���ж�ģʽ                   */
Mode_IRQ            EQU         0x12                                   ;/* �ж�ģʽ                     */
Mode_SVC            EQU         0x13                                   ;/* ����ģʽ                     */
Mode_ABT            EQU         0x17                                   ;/* ��ֹģʽ                     */
Mode_UND            EQU         0x1B                                   ;/* δ����ģʽ                   */
Mode_SYS            EQU         0x1F                                   ;/* ϵͳģʽ                     */

NO_FIQ              EQU         0X80
NO_IRQ              EQU         0X80