#ifndef __PROTOCOL_H__
#define __PROTOCOL_H__

#define VID_FRAME_MAX_SZ    (0xFFFFF - FRAME_MAX_SZ)

#define FRAME_MAX_SZ    253
#define FRAME_DAT_MAX   253
#define FRAME_HDR_SZ    3

#define FRAME_ERR_SZ    3

#define TYPE_MASK       0xE0
#define TYPE_BIT_POS    5
#define SUBS_MASK       0x1F

#define LEN_POS         0
#define CMD0_POS        1
#define CMD1_POS        2
#define DAT_POS         3

/* Error codes */
#define ERR_SUCCESS     0   /* success */
#define ERR_SUBS        1   /* invalid subsystem */
#define ERR_CMD_ID      2   /* invalid command ID */
#define ERR_PARAM       3   /* invalid parameter */
#define ERR_LEN         4   /* invalid length */

#define TYPE_SREQ    		0x1
#define TYPE_SRSP     	0x2

	
#define SUBS_ERR  			0x0
#define SUBS_SYS  			0x1
#define SUBS_VID  			0x3
#define SUBS_MAX  			0x4
	
	
#define REQUEST(len, type, subs, id)	(((len) << (8*LEN_POS)) | \
	(((type) << TYPE_BIT_POS | (subs)) << (8*CMD0_POS)) | ((id) << (8*CMD1_POS)))
	

enum request {

	SYS_VERSION			=	REQUEST(0x0, TYPE_SREQ, SUBS_SYS, 0x0),

	/**
	 * VID SubSystem
	 */
	VID_GET_UCTLS		=	REQUEST(0x0, TYPE_SREQ, SUBS_VID, 0x0), 
	VID_GET_UCTL		=	REQUEST(0x4, TYPE_SREQ, SUBS_VID, 0x1), 
	VID_SET_UCTL		=	REQUEST(0x8, TYPE_SREQ, SUBS_VID, 0x2), 
	VID_SET_UCS2DEF	=	REQUEST(0x0, TYPE_SREQ, SUBS_VID, 0x3), 

	VID_GET_FRMSIZ	=	REQUEST(0x0, TYPE_SREQ, SUBS_VID, 0x10), 
	VID_GET_FMT	    =	REQUEST(0x0, TYPE_SREQ, SUBS_VID, 0x11), 

	VID_REQ_FRAME		=	REQUEST(0x0, TYPE_SREQ, SUBS_VID, 0x20),
};

#define REQUEST_ID(req)     (((req) >> (8*CMD1_POS)) & 0xFF)
#define REQUEST_TYPE(req)   (((req) >> (8*CMD0_POS + TYPE_BIT_POS)) & TYPE_MASK)
#define REQUEST_SUBS(req)   (((req) >> (8*CMD0_POS)) & SUBS_MASK)
#define REQUEST_LEN(req)    (((req) >> (8*LEN_POS)) & 0xFF)


#endif

