/* *
 * * $ID: $
 * * 
 * * This license is set out in https://raw.githubusercontent.com/Broadcom/Broadcom-Compute-Connectivity-Software-robo2-rsdk/master/Legal/LICENSE file.
 * * 
 * * $Copyright: (c) 2020 Broadcom Inc.
 * *
 * * File:
 * *     slic.h
 * * Purpose:
 * *     This file contains definitions internal to SLIC module.
 */

#ifndef CBX_INT_SLIC_H
#define CBX_INT_SLIC_H

#include <sal_types.h>
#include <shared/bitop.h>
#include <shared/types.h>
#include <soc/types.h>
#include <fsal/error.h>
#include <fsal_int/types.h>

#define CHECK_SLIC_INIT(sli)    \
    if (!sli->init)             \
        return CBX_E_INIT;

#define ROBO2_SLIC_RULE_MIN      0
#define ROBO2_SLIC_RULE_MAX      255

#define CBXI_PTP_VSI             4095
#define CBXI_BC_MODE1_VSI        4094

typedef struct slicmap_info_s {
    int           init;         /* TRUE if SLICTCAM has been initialized */
} slicmap_info_t;

/* Mask flags : Flags to indicate which of the bits in the rule are valid */
#define ROBO2_SLIC_MASK_PEPPER   0x1
#define ROBO2_SLIC_MASK_PGMAP    0x2
#define ROBO2_SLIC_MASK_DMAC     0x4
#define ROBO2_SLIC_MASK_SMAC     0x8
#define ROBO2_SLIC_MASK_ETYPE    0x10
#define ROBO2_SLIC_MASK_TPID0    0x20
#define ROBO2_SLIC_MASK_TPID1    0x40
#define ROBO2_SLIC_MASK_TCI      0x80
#define ROBO2_SLIC_TCI0_SHIFT    0
#define ROBO2_SLIC_TCI1_SHIFT    1
#define ROBO2_SLIC_TCI2_SHIFT    2
#define ROBO2_SLIC_TCI3_SHIFT    3
#define ROBO2_SLIC_TCI4_SHIFT    4

typedef enum {
    ETYPE_PAYLOAD         = 0,
    ETYPE_LLC             = 1,
    ETYPE_IPV4            = 2,
    ETYPE_IPV6            = 3,
    ETYPE_UCMPLS          = 4,
    ETYPE_MCMPLS          = 5,
    ETYPE_PTP             = 6,
    ETYPE_ARP             = 7,
    ETYPE_USER_ETYPE8     = 8,
    ETYPE_USER_ETYPE9     = 9,
    ETYPE_USER_ETYPE10    = 10,
    ETYPE_USER_ETYPE11    = 11,
    ETYPE_USER_ETYPE12    = 12,
    ETYPE_USER_ETYPE13    = 13,
    ETYPE_USER_ETYPE14    = 14,
    ETYPE_USER_ETYPE15    = 15,
} cbxi_slicmap_etype_t;

typedef enum {
    ARL_KEY_NO_KEY        = 0,
    ARL_KEY_FID_MAC       = 1,
    ARL_KEY_FID_IPA       = 2,
    ARL_KEY_FID_MPLS      = 3,
    ARL_KEY_SPG_ECID      = 4,
    ARL_KEY_FID_MIM       = 5,
} cbxi_srl_key_t;

typedef enum {
    TPID_STAG             = 1,
    TPID_CTAG             = 2,
    TPID_ETAG             = 3,
    TPID_ITAG             = 4,
    TPID_PPPOE            = 5,
    TPID_SNAP             = 6,
    USER_TPID7            = 7,
} cbxi_tpid_t;

/* Header decapsulation list */
typedef enum {
    HDT_CTAG_DECAP              = 1,
    HDT_STAG_DECAP              = 2,
    HDT_STAG_CTAG_DECAP         = 3,
    HDT_ETAG_DECAP              = 4,
    HDT_MIM_DECAP               = 5,
} cbxi_hdt_id_t;

/* soft tag list */
typedef enum {
    SOFT_TAG_ALT_STAG           = 0,
    SOFT_TAG_ALT_CTAG           = 1,
    SOFT_TAG_AUTOLOOP           = 2,
    SOFT_TAG_EAPOL              = 3,
    SOFT_TAG_MIM_LITE           = 4,
    SOFT_TAG_LLDP               = 5,
    SOFT_TAG_RESERVED           = 6,
} cbxi_stt_id_t;

/* FPSLIC list */
typedef enum {
    SLICID_DEFAULT              = 0,
    SLICID_USE_DP               = 1,
    SLICID_MPLS_ARL             = 2,
    SLICID_MIM_ARL              = 3,
    SLICID_MIM_ARL_N_DECAP      = 4,
    SLICID_EARLY_ACK            = 5,
    SLICID_EAPOL                = 6,
    SLICID_PV_TYPE              = 7,
    SLICID_PV_TYPE_STAG         = 8,
    SLICID_PV_TYPE_CTAG         = 9,
    SLICID_LIN_TYPE_STAG        = 10,
    SLICID_LIN_TYPE_CTAG        = 11,
    SLICID_PE_IN_ECID_U0_P0     = 12,
    SLICID_PE_IN_ECID_U0_P1     = 13,
    SLICID_PE_IN_ECID_U0_P2     = 14,
    SLICID_PE_IN_ECID_U0_P3     = 15,
    SLICID_PE_IN_ECID_U0_P4     = 16,
    SLICID_PE_IN_ECID_U0_P5     = 17,
    SLICID_PE_IN_ECID_U0_P6     = 18,
    SLICID_PE_IN_ECID_U0_P7     = 19,
    SLICID_PE_IN_ECID_U0_P8     = 20,
    SLICID_PE_IN_ECID_U0_P9     = 21,
    SLICID_PE_IN_ECID_U0_P10    = 22,
    SLICID_PE_IN_ECID_U0_P11    = 23,
    SLICID_PE_IN_ECID_U0_P12    = 24,
    SLICID_PE_IN_ECID_U0_P13    = 25,
    SLICID_PE_IN_ECID_U0_P14    = 26,
    SLICID_PE_IN_ECID_U0_P15    = 27,
    SLICID_PE_IN_ECID_U1_P0     = 28,
    SLICID_PE_IN_ECID_U1_P1     = 29,
    SLICID_PE_IN_ECID_U1_P2     = 30,
    SLICID_PE_IN_ECID_U1_P3     = 31,
    SLICID_PE_IN_ECID_U1_P4     = 32,
    SLICID_PE_IN_ECID_U1_P5     = 33,
    SLICID_PE_IN_ECID_U1_P6     = 34,
    SLICID_PE_IN_ECID_U1_P7     = 35,
    SLICID_PE_IN_ECID_U1_P8     = 36,
    SLICID_PE_IN_ECID_U1_P9     = 37,
    SLICID_PE_IN_ECID_U1_P10    = 38,
    SLICID_PE_IN_ECID_U1_P11    = 39,
    SLICID_PE_IN_ECID_U1_P12    = 40,
    SLICID_PE_IN_ECID_U1_P13    = 41,
    SLICID_PE_IN_ECID_U1_P14    = 42,
    SLICID_PE_IN_ECID_U1_P15    = 43,
    SLICID_PE_IN_ECID_LAG0      = 44,
    SLICID_PE_IN_ECID_LAG1      = 45,
    SLICID_PE_IN_ECID_LAG2      = 46,
    SLICID_PE_IN_ECID_LAG3      = 47,
    SLICID_PE_IN_ECID_LAG4      = 48,
    SLICID_PE_IN_ECID_LAG5      = 49,
    SLICID_PE_IN_ECID_LAG6      = 50,
    SLICID_PE_IN_ECID_LAG7      = 51,
    SLICID_PE_IN_ECID_LAG8      = 52,
    SLICID_PE_IN_ECID_LAG9      = 53,
    SLICID_PE_IN_ECID_LAG10     = 54,
    SLICID_PE_IN_ECID_LAG11     = 55,
    SLICID_PE_IN_ECID_LAG12     = 56,
    SLICID_PE_IN_ECID_LAG13     = 57,
    SLICID_PE_IN_ECID_LAG14     = 58,
    SLICID_PE_IN_ECID_LAG15     = 59,
    SLICID_PE_IN_ECID_LAG16     = 60,
    SLICID_PE_IN_ECID_LAG17     = 61,
    SLICID_PE_IN_ECID_LAG18     = 62,
    SLICID_PE_IN_ECID_LAG19     = 63,
    SLICID_PE_IN_ECID_LAG20     = 64,
    SLICID_PE_IN_ECID_LAG21     = 65,
    SLICID_PE_IN_ECID_LAG22     = 66,
    SLICID_PE_IN_ECID_LAG23     = 67,
    SLICID_PE_IN_ECID_LAG24     = 68,
    SLICID_PE_IN_ECID_LAG25     = 69,
    SLICID_PE_IN_ECID_LAG26     = 70,
    SLICID_PE_IN_ECID_LAG27     = 71,
    SLICID_PE_IN_ECID_LAG28     = 72,
    SLICID_PE_IN_ECID_LAG29     = 73,
    SLICID_PE_IN_ECID_LAG30     = 74,
    SLICID_PE_IN_ECID_LAG31     = 75,
    SLICID_PE_ETAG_DECAP_LB     = 76, /* Decap with Loopback port */
    SLICID_PE_ETAG_DECAP        = 77, /* Decap without LB port */
    SLICID_PE_FWD_DWNSTR_UC     = 78,
    SLICID_PE_FWD_DWNSTR_MC     = 79,
    SLICID_PE_FWD_UPSTR         = 80,
    SLICID_LWIP                 = 81,
    SLICID_LLDP                 = 82,
    /* Dedicated SLICs for Ethernet and UDP PTP received on
       Physical ports 0 through 15 */
    SLICID_PTP_ETH_PP0          = 83,
    SLICID_PTP_ETH_PP1          = 84,
    SLICID_PTP_ETH_PP2          = 85,
    SLICID_PTP_ETH_PP3          = 86,
    SLICID_PTP_ETH_PP4          = 87,
    SLICID_PTP_ETH_PP5          = 88,
    SLICID_PTP_ETH_PP6          = 89,
    SLICID_PTP_ETH_PP7          = 90,
    SLICID_PTP_ETH_PP8          = 91,
    SLICID_PTP_ETH_PP9          = 92,
    SLICID_PTP_ETH_PP10         = 93,
    SLICID_PTP_ETH_PP11         = 94,
    SLICID_PTP_ETH_PP12         = 95,
    SLICID_PTP_ETH_PP13         = 96,
    SLICID_PTP_ETH_PP14         = 97,
    SLICID_PTP_ETH_PP15         = 98,
    SLICID_PTP_UDP_PP0          = 99,
    SLICID_PTP_UDP_PP1          = 100,
    SLICID_PTP_UDP_PP2          = 101,
    SLICID_PTP_UDP_PP3          = 102,
    SLICID_PTP_UDP_PP4          = 103,
    SLICID_PTP_UDP_PP5          = 104,
    SLICID_PTP_UDP_PP6          = 105,
    SLICID_PTP_UDP_PP7          = 106,
    SLICID_PTP_UDP_PP8          = 107,
    SLICID_PTP_UDP_PP9          = 108,
    SLICID_PTP_UDP_PP10         = 109,
    SLICID_PTP_UDP_PP11         = 110,
    SLICID_PTP_UDP_PP12         = 111,
    SLICID_PTP_UDP_PP13         = 112,
    SLICID_PTP_UDP_PP14         = 113,
    SLICID_PTP_UDP_PP15         = 114,
    SLICID_PTP                  = 115,
    SLICID_MAX_INDEX            = 116, /* Last slicid used + 1 */
} cbxi_slicid_t;


/* SLIC rule list
 * NOTE: enum number should follow rule numbers in same order*/
typedef enum {
    SLIC_CSD_DEV1_DROP              = 0, /* Drop CB header with devid 1 in secondary */
    SLIC_CSD_DEV0_FWD               = 1, /* Forward CB header with devid 0 in secondary */
    SLIC_HOST_PORT                  = 2, /* Host Port */
    /* Tunnels */
    SLIC_MPLS_UC                    = 3, /* MPLS Unicast */
    SLIC_MPLS_MC                    = 4, /* MPLS Multi cast */
    SLIC_MIM_ENDING                 = 5, /* MIM -  ending */
    SLIC_MIM                        = 6, /* MIM */
    SLIC_MIM_LITE_CUST              = 7, /* MIM lite cust */
    SLIC_MIM_LITE_TUNNEL            = 8, /* MIM lite tunnel */
    SLIC_MIM_LITE                   = 9, /* MIM lite */
    /* Tag drop rules */
    SLIC_DROP_CTAG                  = 10, /* Drop CTAG */
    SLIC_DROP_STAG                  = 11, /* Drop STAG */
    SLIC_DROP_UTAG                  = 12, /* Drop Un tagged */
    SLIC_DROP_PRI_TAG               = 13, /* Drop Priority tagged */
    /* Protocol rules */
    SLIC_TAS                        = 14, /* TAS */
    SLIC_PTP_ETH_PORT_0             = 15, /* Ethernet PTP Received on Port 0 */
    SLIC_PTP_ETH_PORT_1             = 16, /* Ethernet PTP Received on Port 1 */
    SLIC_PTP_ETH_PORT_2             = 17, /* Ethernet PTP Received on Port 2 */
    SLIC_PTP_ETH_PORT_3             = 18, /* Ethernet PTP Received on Port 3 */
    SLIC_PTP_ETH_PORT_4             = 19, /* Ethernet PTP Received on Port 4 */
    SLIC_PTP_ETH_PORT_5             = 20, /* Ethernet PTP Received on Port 5 */
    SLIC_PTP_ETH_PORT_6             = 21, /* Ethernet PTP Received on Port 6 */
    SLIC_PTP_ETH_PORT_7             = 22, /* Ethernet PTP Received on Port 7 */
    SLIC_PTP_ETH_PORT_8             = 23, /* Ethernet PTP Received on Port 8 */
    SLIC_PTP_ETH_PORT_9             = 24, /* Ethernet PTP Received on Port 9 */
    SLIC_PTP_ETH_PORT_10            = 25, /* Ethernet PTP Received on Port 10 */
    SLIC_PTP_ETH_PORT_11            = 26, /* Ethernet PTP Received on Port 11 */
    SLIC_PTP_ETH_PORT_12            = 27, /* Ethernet PTP Received on Port 12 */
    SLIC_PTP_ETH_PORT_13            = 28, /* Ethernet PTP Received on Port 13 */
    SLIC_PTP_ETH_PORT_14            = 29, /* Ethernet PTP Received on Port 14 */
    SLIC_PTP_ETH_PORT_15            = 30, /* Ethernet PTP Received on Port 15 */
    SLIC_PTP_ETH_P2P_PORT_0         = 31, /* Ethernet PTP peer msg Received on Port 0 */
    SLIC_PTP_ETH_P2P_PORT_1         = 32, /* Ethernet PTP peer msg Received on Port 1 */
    SLIC_PTP_ETH_P2P_PORT_2         = 33, /* Ethernet PTP peer msg Received on Port 2 */
    SLIC_PTP_ETH_P2P_PORT_3         = 34, /* Ethernet PTP peer msg Received on Port 3 */
    SLIC_PTP_ETH_P2P_PORT_4         = 35, /* Ethernet PTP peer msg Received on Port 4 */
    SLIC_PTP_ETH_P2P_PORT_5         = 36, /* Ethernet PTP peer msg Received on Port 5 */
    SLIC_PTP_ETH_P2P_PORT_6         = 37, /* Ethernet PTP peer msg Received on Port 6 */
    SLIC_PTP_ETH_P2P_PORT_7         = 38, /* Ethernet PTP peer msg Received on Port 7 */
    SLIC_PTP_ETH_P2P_PORT_8         = 39, /* Ethernet PTP peer msg Received on Port 8 */
    SLIC_PTP_ETH_P2P_PORT_9         = 40, /* Ethernet PTP peer msg Received on Port 9 */
    SLIC_PTP_ETH_P2P_PORT_10        = 41, /* Ethernet PTP peer msg Received on Port 10 */
    SLIC_PTP_ETH_P2P_PORT_11        = 42, /* Ethernet PTP peer msg Received on Port 11 */
    SLIC_PTP_ETH_P2P_PORT_12        = 43, /* Ethernet PTP peer msg Received on Port 12 */
    SLIC_PTP_ETH_P2P_PORT_13        = 44, /* Ethernet PTP peer msg Received on Port 13 */
    SLIC_PTP_ETH_P2P_PORT_14        = 45, /* Ethernet PTP peer msg Received on Port 14 */
    SLIC_PTP_ETH_P2P_PORT_15        = 46, /* Ethernet PTP peer msg Received on Port 15 */
    SLIC_PTP_UDP_PORT_0             = 47, /* UDP PTP Received on Port 0 */
    SLIC_PTP_UDP_PORT_1             = 48, /* UDP PTP Received on Port 1 */
    SLIC_PTP_UDP_PORT_2             = 49, /* UDP PTP Received on Port 2 */
    SLIC_PTP_UDP_PORT_3             = 50, /* UDP PTP Received on Port 3 */
    SLIC_PTP_UDP_PORT_4             = 51, /* UDP PTP Received on Port 4 */
    SLIC_PTP_UDP_PORT_5             = 52, /* UDP PTP Received on Port 5 */
    SLIC_PTP_UDP_PORT_6             = 53, /* UDP PTP Received on Port 6 */
    SLIC_PTP_UDP_PORT_7             = 54, /* UDP PTP Received on Port 7 */
    SLIC_PTP_UDP_PORT_8             = 55, /* UDP PTP Received on Port 8 */
    SLIC_PTP_UDP_PORT_9             = 56, /* UDP PTP Received on Port 9 */
    SLIC_PTP_UDP_PORT_10            = 57, /* UDP PTP Received on Port 10 */
    SLIC_PTP_UDP_PORT_11            = 58, /* UDP PTP Received on Port 11 */
    SLIC_PTP_UDP_PORT_12            = 59, /* UDP PTP Received on Port 12 */
    SLIC_PTP_UDP_PORT_13            = 60, /* UDP PTP Received on Port 13 */
    SLIC_PTP_UDP_PORT_14            = 61, /* UDP PTP Received on Port 14 */
    SLIC_PTP_UDP_PORT_15            = 62, /* UDP PTP Received on Port 15 */
    SLIC_PTP_UDP_P2P_PORT_0         = 63, /* UDP PTP peer msg Received on Port 0 */
    SLIC_PTP_UDP_P2P_PORT_1         = 64, /* UDP PTP peer msg Received on Port 1 */
    SLIC_PTP_UDP_P2P_PORT_2         = 65, /* UDP PTP peer msg Received on Port 2 */
    SLIC_PTP_UDP_P2P_PORT_3         = 66, /* UDP PTP peer msg Received on Port 3 */
    SLIC_PTP_UDP_P2P_PORT_4         = 67, /* UDP PTP peer msg Received on Port 4 */
    SLIC_PTP_UDP_P2P_PORT_5         = 68, /* UDP PTP peer msg Received on Port 5 */
    SLIC_PTP_UDP_P2P_PORT_6         = 69, /* UDP PTP peer msg Received on Port 6 */
    SLIC_PTP_UDP_P2P_PORT_7         = 70, /* UDP PTP peer msg Received on Port 7 */
    SLIC_PTP_UDP_P2P_PORT_8         = 71, /* UDP PTP peer msg Received on Port 8 */
    SLIC_PTP_UDP_P2P_PORT_9         = 72, /* UDP PTP peer msg Received on Port 9 */
    SLIC_PTP_UDP_P2P_PORT_10        = 73, /* UDP PTP peer msg Received on Port 10 */
    SLIC_PTP_UDP_P2P_PORT_11        = 74, /* UDP PTP peer msg Received on Port 11 */
    SLIC_PTP_UDP_P2P_PORT_12        = 75, /* UDP PTP peer msg Received on Port 12 */
    SLIC_PTP_UDP_P2P_PORT_13        = 76, /* UDP PTP peer msg Received on Port 13 */
    SLIC_PTP_UDP_P2P_PORT_14        = 77, /* UDP PTP peer msg Received on Port 14 */
    SLIC_PTP_UDP_P2P_PORT_15        = 78, /* UDP PTP peer msg Received on Port 15 */
    SLIC_LLC                        = 79, /* LLC */
    SLIC_ARP_BCAST                  = 80, /* ARP BCAST */
    SLIC_ARP_UCAST                  = 81, /* ARP UCAST */
    SLIC_SYS_MAC_IPV4               = 82, /* IPv4 pkt with system MAC as DMAC */
    SLIC_SYS_MAC_IPV6               = 83, /* IPv6 pkt with system MAC as DMAC */
    SLIC_SYS_MAC_DROP               = 84, /* Drop pkt with system MAC as DMAC */
    SLIC_LLDP                       = 85, /* LLDP */
    /* SLIC rules rearranged to filter EAPOL frames with user defined MACs */
    SLIC_EAPOL_IEEE                 = 86, /* EAPOL IEEE MAC */
    SLIC_EAPOL_UCAST                = 87, /* EAPOL user defined unicast */
    SLIC_EAPOL_MCAST                = 88, /* EAPOL user defined multicast */
    SLIC_EAPOL_ETYPE                = 89, /* EAPOL etype = 0x888E only */
    SLIC_RSVD_MAC_1                 = 90, /* Reserved MAC 01:80:C2:00:00:10-1F*/
    SLIC_RSVD_MAC_2                 = 91, /* Reserved MAC 01:80:C2:00:00:20-21*/
    SLIC_L2CP                       = 92, /* L2CP */
    SLIC_EAPOL_DROP                 = 93, /* EAPOL drop other packets */
    /* Port Extender */
    SLIC_PE_1BR_DROP                = 94, /* Drop 1BR ETAG packets */
    SLIC_PE_1BR_FWD_UPSTR           = 95, /* Fwd 1BR ETAG packets (PE CSD port)*/
    /* Rules to filter UCAST ETAGs */
    SLIC_PE_1BR_UC_ETAG_U0_P0       = 96, /* UCAST ETAG U0 Port 0  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P1       = 97, /* UCAST ETAG U0 Port 1  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P2       = 98, /* UCAST ETAG U0 Port 2  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P3       = 99, /* UCAST ETAG U0 Port 3  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P4       = 100, /* UCAST ETAG U0 Port 4  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P5       = 101, /* UCAST ETAG U0 Port 5  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P6       = 102, /* UCAST ETAG U0 Port 6  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P7       = 103, /* UCAST ETAG U0 Port 7  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P8       = 104, /* UCAST ETAG U0 Port 8  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P9       = 105, /* UCAST ETAG U0 Port 9  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P10      = 106, /* UCAST ETAG U0 Port 10  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P11      = 107, /* UCAST ETAG U0 Port 11  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P12      = 108, /* UCAST ETAG U0 Port 12  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P13      = 109, /* UCAST ETAG U0 Port 13  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P14      = 110, /* UCAST ETAG U0 Port 14  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U0_P15      = 111, /* UCAST ETAG U0 Port 15  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P0       = 112, /* UCAST ETAG U1 Port 0  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P1       = 113, /* UCAST ETAG U1 Port 1  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P2       = 114, /* UCAST ETAG U1 Port 2  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P3       = 115, /* UCAST ETAG U1 Port 3  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P4       = 116, /* UCAST ETAG U1 Port 4  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P5       = 117, /* UCAST ETAG U1 Port 5  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P6       = 118, /* UCAST ETAG U1 Port 6  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P7       = 119, /* UCAST ETAG U1 Port 7  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P8       = 120, /* UCAST ETAG U1 Port 8  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P9       = 121, /* UCAST ETAG U1 Port 9  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P10      = 122, /* UCAST ETAG U1 Port 10  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P11      = 123, /* UCAST ETAG U1 Port 11  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P12      = 124, /* UCAST ETAG U1 Port 12  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P13      = 125, /* UCAST ETAG U1 Port 13  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P14      = 126, /* UCAST ETAG U1 Port 14  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_U1_P15      = 127, /* UCAST ETAG U1 Port 15  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG0        = 128, /* UCAST ETAG LAG 0  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG1        = 129, /* UCAST ETAG LAG 1  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG2        = 130, /* UCAST ETAG LAG 2  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG3        = 131, /* UCAST ETAG LAG 3  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG4        = 132, /* UCAST ETAG LAG 4  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG5        = 133, /* UCAST ETAG LAG 5  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG6        = 134, /* UCAST ETAG LAG 6  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG7        = 135, /* UCAST ETAG LAG 7  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG8        = 136, /* UCAST ETAG LAG 8  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG9        = 137, /* UCAST ETAG LAG 9  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG10       = 138, /* UCAST ETAG LAG 10  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG11       = 139, /* UCAST ETAG LAG 11  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG12       = 140, /* UCAST ETAG LAG 12  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG13       = 141, /* UCAST ETAG LAG 13  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG14       = 142, /* UCAST ETAG LAG 14  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG15       = 143, /* UCAST ETAG LAG 15  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG16       = 144, /* UCAST ETAG LAG 16  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG17       = 145, /* UCAST ETAG LAG 17  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG18       = 146, /* UCAST ETAG LAG 18  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG19       = 147, /* UCAST ETAG LAG 19  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG20       = 148, /* UCAST ETAG LAG 20  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG21       = 149, /* UCAST ETAG LAG 21  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG22       = 150, /* UCAST ETAG LAG 22  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG23       = 151, /* UCAST ETAG LAG 23  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG24       = 152, /* UCAST ETAG LAG 24  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG25       = 153, /* UCAST ETAG LAG 25  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG26       = 154, /* UCAST ETAG LAG 26  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG27       = 155, /* UCAST ETAG LAG 27  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG28       = 156, /* UCAST ETAG LAG 28  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG29       = 157, /* UCAST ETAG LAG 29  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG30       = 158, /* UCAST ETAG LAG 30  (Uplink port)*/
    SLIC_PE_1BR_UC_ETAG_LAG31       = 159, /* UCAST ETAG LAG 31  (Uplink port)*/
    /* Rules to filter matching Ingress ECID for MCAST
     * Access PE : Set rules on Uplink port and Decap ETAG
     * Transit PE: Set rules on Loopback port P14 and Decap ETAG */
    SLIC_PE_1BR_IN_ECID_U0_P0       = 160, /* Fwd 1BR ETAG U0 Port 0  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P1       = 161, /* Fwd 1BR ETAG U0 Port 1  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P2       = 162, /* Fwd 1BR ETAG U0 Port 2  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P3       = 163, /* Fwd 1BR ETAG U0 Port 3  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P4       = 164, /* Fwd 1BR ETAG U0 Port 4  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P5       = 165, /* Fwd 1BR ETAG U0 Port 5  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P6       = 166, /* Fwd 1BR ETAG U0 Port 6  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P7       = 167, /* Fwd 1BR ETAG U0 Port 7  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P8       = 168, /* Fwd 1BR ETAG U0 Port 8  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P9       = 169, /* Fwd 1BR ETAG U0 Port 9  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P10      = 170, /* Fwd 1BR ETAG U0 Port 10  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P11      = 171, /* Fwd 1BR ETAG U0 Port 11  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P12      = 172, /* Fwd 1BR ETAG U0 Port 12  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P13      = 173, /* Fwd 1BR ETAG U0 Port 13  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P14      = 174, /* Fwd 1BR ETAG U0 Port 14  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U0_P15      = 175, /* Fwd 1BR ETAG U0 Port 15  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P0       = 176, /* Fwd 1BR ETAG U1 Port 0  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P1       = 177, /* Fwd 1BR ETAG U1 Port 1  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P2       = 178, /* Fwd 1BR ETAG U1 Port 2  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P3       = 179, /* Fwd 1BR ETAG U1 Port 3  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P4       = 180, /* Fwd 1BR ETAG U1 Port 4  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P5       = 181, /* Fwd 1BR ETAG U1 Port 5  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P6       = 182, /* Fwd 1BR ETAG U1 Port 6  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P7       = 183, /* Fwd 1BR ETAG U1 Port 7  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P8       = 184, /* Fwd 1BR ETAG U1 Port 8  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P9       = 185, /* Fwd 1BR ETAG U1 Port 9  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P10      = 186, /* Fwd 1BR ETAG U1 Port 10  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P11      = 187, /* Fwd 1BR ETAG U1 Port 11  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P12      = 188, /* Fwd 1BR ETAG U1 Port 12  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P13      = 189, /* Fwd 1BR ETAG U1 Port 13  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P14      = 190, /* Fwd 1BR ETAG U1 Port 14  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_U1_P15      = 191, /* Fwd 1BR ETAG U1 Port 15  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG0        = 192, /* Fwd 1BR ETAG LAG 0  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG1        = 193, /* Fwd 1BR ETAG LAG 1  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG2        = 194, /* Fwd 1BR ETAG LAG 2  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG3        = 195, /* Fwd 1BR ETAG LAG 3  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG4        = 196, /* Fwd 1BR ETAG LAG 4  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG5        = 197, /* Fwd 1BR ETAG LAG 5  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG6        = 198, /* Fwd 1BR ETAG LAG 6  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG7        = 199, /* Fwd 1BR ETAG LAG 7  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG8        = 200, /* Fwd 1BR ETAG LAG 8  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG9        = 201, /* Fwd 1BR ETAG LAG 9  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG10       = 202, /* Fwd 1BR ETAG LAG 10  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG11       = 203, /* Fwd 1BR ETAG LAG 11  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG12       = 204, /* Fwd 1BR ETAG LAG 12  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG13       = 205, /* Fwd 1BR ETAG LAG 13  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG14       = 206, /* Fwd 1BR ETAG LAG 14  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG15       = 207, /* Fwd 1BR ETAG LAG 15  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG16       = 208, /* Fwd 1BR ETAG LAG 16  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG17       = 209, /* Fwd 1BR ETAG LAG 17  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG18       = 210, /* Fwd 1BR ETAG LAG 18  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG19       = 211, /* Fwd 1BR ETAG LAG 19  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG20       = 212, /* Fwd 1BR ETAG LAG 20  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG21       = 213, /* Fwd 1BR ETAG LAG 21  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG22       = 214, /* Fwd 1BR ETAG LAG 22  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG23       = 215, /* Fwd 1BR ETAG LAG 23  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG24       = 216, /* Fwd 1BR ETAG LAG 24  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG25       = 217, /* Fwd 1BR ETAG LAG 25  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG26       = 218, /* Fwd 1BR ETAG LAG 26  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG27       = 219, /* Fwd 1BR ETAG LAG 27  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG28       = 220, /* Fwd 1BR ETAG LAG 28  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG29       = 221, /* Fwd 1BR ETAG LAG 29  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG30       = 222, /* Fwd 1BR ETAG LAG 30  (Uplink port)*/
    SLIC_PE_1BR_IN_ECID_LAG31       = 223, /* Fwd 1BR ETAG LAG 31  (Uplink port)*/
    SLIC_PE_1BR_DECAP               = 224, /* Decap 1BR ETAG packets (Uplink port)*/
    /* Default Downstream rule of Uplink port:
     * Access PE : Decap ETAG
     * Transit PE: No Decap*/
    SLIC_PE_1BR_FWD_DWNSTR_UC       = 225, /* Fwd 1BR ETAG packets (Uplink port)*/
    SLIC_PE_1BR_FWD_DWNSTR_MC       = 226, /* Fwd 1BR ETAG packets (Uplink port)*/
    SLIC_PE_UNTAG_DROP              = 227, /* Drop packets without ETAG*/
    SLIC_PE_UNTAG_FWD               = 228, /* Fwd pkts w/o ETAG (Extender port)*/
    /* Bridging */
    SLIC_PORT_BASED_VLAN            = 229, /* Port based VLAN bridging */
    SLIC_CUSTOMER_PORT_VLAN         = 230, /* VLAN bridging: Customer port */
    SLIC_PROVIDER_PORT_VLAN         = 231, /* VLAN bridging: Provider port */
    SLIC_CUSTOMER_PORT_LIN          = 232, /* LIN mode : Customer port */
    SLIC_PROVIDER_PORT_LIN          = 233, /* LIN mode : Provider port */
 /* Bridging (with Trust) */
    SLIC_TRUST_PORT_BASED_VLAN      = 234, /* Port based VLAN bridging */
    SLIC_TRUST_CUSTOMER_PORT_VLAN   = 235, /* VLAN bridging: Customer port */
    SLIC_TRUST_PROVIDER_PORT_VLAN   = 236, /* VLAN bridging: Provider port */
    SLIC_TRUST_CUSTOMER_PORT_LIN    = 237, /* LIN mode : Customer port */
    SLIC_TRUST_PROVIDER_PORT_LIN    = 238, /* LIN mode : Provider port */
    /* Default forwarding */
    SLIC_DEFAULT                    = 239, /* Default forwarding: last rule*/
    SLIC_MAX_INDEX                  = 240, /* Last entry in the enum */
} cbxi_slic_rule_id_t;

typedef struct cbxi_slic_rule_s {
    uint16_t pepper;
    uint16_t pepper_mask;
    uint16_t pg_map;
    uint16_t smac_hi_16;
    uint16_t smac_hi_mask;
    uint32_t smac_lo_32;
    uint32_t smac_lo_mask;
    uint16_t dmac_lo_16;
    uint16_t dmac_lo_mask;
    uint32_t dmac_hi_32;
    uint32_t dmac_hi_mask;
    uint8_t  tpid0;
    uint8_t  tpid1;
    uint16_t tci0;
    uint16_t tci0_mask;
    uint16_t tci1;
    uint16_t tci1_mask;
    uint16_t tci2;
    uint16_t tci2_mask;
    uint16_t tci3;
    uint16_t tci3_mask;
    uint16_t tci4;
    uint16_t tci4_mask;
    uint8_t  tci_valid;
    uint8_t  tci_valid_mask;
    cbxi_slicmap_etype_t etype;
    uint32_t mask_flags;
} cbxi_slic_rule_t;


extern int cbxi_slictcam_init(void);
extern int cbxi_slicmap_rule_set(int unit,
        cbxi_slic_rule_id_t rule_number, cbxi_slic_rule_t rule);
extern int cbxi_slicmap_rule_get(int unit,
        cbxi_slic_rule_id_t rule_number, cbxi_slic_rule_t *rule);
extern int cbxi_slic_pgmap_set(int unit,
                cbxi_slic_rule_id_t rule_number, pbmp_t pg_map);
extern int cbxi_slic_pgmap_get(int unit,
                cbxi_slic_rule_id_t rule_number, pbmp_t *pg_map);
extern int cbxi_slic_rule_validate(int unit,
                cbxi_slic_rule_id_t rule_number, uint8_t valid);


#endif /* CBX_INT_SLIC_H */