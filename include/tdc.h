/*
 * tdc.h
 *
 *  Created on: 2013-11-7
 *      Author: liming
 */

#ifndef TDC_H_
#define TDC_H_


typedef struct TDC_DATA{
	_fp32 ptime[4];  //pt1~4
	_fp32 ftime1;  //fire_up
	_fp32 ftime2;  //fire_down
	_fp32 time_delta;
	_u32 cal;    //calibration
} TDCDATA;
typedef struct TDC_INFO{
	_u32 tdc_mode;
	_u32 mrange;
	_u32 disautocal;
	_u32 hitin1;
	_u32 tdc_opt;
	TDCDATA tdc_data;
	_u32 result[16];   //原始数据
	_fp32 res[16];      //处理后的数据
	_u32 current_ptr0;
	_u32 current_ptr1;
	_u32 last_ptr0;
	_u32 last_ptr1;
	_u32 res_num;    //正确的结果个数
	_u32 change_flow_direction;  //交换流量测量方向
	_u32 sonar_PulseDef;
	_u32 sonar_ResPtr;
	_u32 mop;
	_u32 err;
} TDCINFO;


#define S_TDC	2
#define R_TDC	1
#define H_TDC	0

#define mode_0   0    //once   time   measure
#define mode_1   1    //once   thsens measure
#define mode_2   2    //twice  time   measure
#define mode_3   3    //twice  thsens measure
#define mode_4   4    //tdc    cal
#define mode_5   5    //clkhs  cal
#define mode_6   6    //cap    detection

/////STDC parameter
#define stdc_m1roundo 0x3ffff  //  18bit mrange1 Double/Single precision out-round count
#define stdc_m2roundo  0xffff  //9/10bit mrange2 Double/Single precision out-round count
#define stdc_droundi     0x7f  // 7bit mrange1/2 Double precision  in-round count
#define stdc_sroundi     0x3f  // 6bit mrange1/2 Single precision  in-round count
#define stdc_double       126  //Double precision 2^n supplement
#define stdc_single        63  //Single precision 2^n supplement

/*
 * ls1d_InitTdc
 * 初始化tdc寄存器，使用推荐配置，但没有指定tdc的类型。
 */
void ls1d_InitTdc(void);

/*
 * ls1d_tdc_select
 * 选择特定种类的tdc进行时间测量。
 */
void ls1d_tdc_select(_u32 mode);

/*
 * Tdc_mop
 * 选择tdc测量类型，参考PMU_command寄存器手册。
 */
void Tdc_mop(_u32 timing, _u32 mode);

/*
 * ls1d_tdc_start
 * 执行一次tdc测量。
 */
void ls1d_tdc_start();

/*
 * res_ready
 * 等res_ready来临后，对测量数据进行检查并计算。
 */
_u32 res_ready(void);

#endif /* TDC_H_ */
