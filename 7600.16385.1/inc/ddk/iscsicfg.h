#ifndef _iscsicfg_h_
#define _iscsicfg_h_

// MSiSCSI_TCPIPConfig - MSiSCSI_TCPIPConfig


//***************************************************************************
//
//  iscsicfg.h
// 
//  Module: iScsi Discovery api
//
//  Purpose: Header defining interface between user mode configuration
//           apps and HBA driver miniport.
//
//  Copyright (c) 2001 Microsoft Corporation
//
//***************************************************************************

#include <iscsidef.h>

//
//
// This class is required.
//
// TCP/IP configuration class, implement one instance for each IP address on
// your adapter. For example, if you adapter supports 3 IP addresses then
// your adapter would implement 3 instances of this class.
//
// This class uses PDO instance names with 1 instance for each TCP/IP interface.
//

#define MSiSCSI_TCPIPConfigGuid \
    { 0x7a2c6c2b,0xe5a5,0x49ad, { 0xad,0x68,0x13,0x30,0x89,0xac,0xd7,0x4d } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(MSiSCSI_TCPIPConfig_GUID, \
            0x7a2c6c2b,0xe5a5,0x49ad,0xad,0x68,0x13,0x30,0x89,0xac,0xd7,0x4d);
#endif


typedef struct _MSiSCSI_TCPIPConfig
{
    // TRUE if the adapter should use an autogenerated and non routable (link local) address as its IP address.
    BOOLEAN UseLinkLocalAddress;
    #define MSiSCSI_TCPIPConfig_UseLinkLocalAddress_SIZE sizeof(BOOLEAN)
    #define MSiSCSI_TCPIPConfig_UseLinkLocalAddress_ID 1

    // TRUE if the adapter should use DHCP to discovery its IP address information.
    BOOLEAN EnableDHCP;
    #define MSiSCSI_TCPIPConfig_EnableDHCP_SIZE sizeof(BOOLEAN)
    #define MSiSCSI_TCPIPConfig_EnableDHCP_ID 2

    // TRUE if the adapter should use DHCP to discover DNS addresses.
    BOOLEAN UseDHCPForDNS;
    #define MSiSCSI_TCPIPConfig_UseDHCPForDNS_SIZE sizeof(BOOLEAN)
    #define MSiSCSI_TCPIPConfig_UseDHCPForDNS_ID 3

    // IP Versions supported **Add #defines**
    ULONG IPVersions;
    #define MSiSCSI_TCPIPConfig_IPVersions_SIZE sizeof(ULONG)
    #define MSiSCSI_TCPIPConfig_IPVersions_ID 4

    // IP address of the adapter
    ISCSI_IP_Address IpAddress;
    #define MSiSCSI_TCPIPConfig_IpAddress_SIZE sizeof(ISCSI_IP_Address)
    #define MSiSCSI_TCPIPConfig_IpAddress_ID 5

    // Static Default Gateway IP address
    ISCSI_IP_Address DefaultGateway;
    #define MSiSCSI_TCPIPConfig_DefaultGateway_SIZE sizeof(ISCSI_IP_Address)
    #define MSiSCSI_TCPIPConfig_DefaultGateway_ID 6

    // Static Subnet Mask
    ISCSI_IP_Address SubnetMask;
    #define MSiSCSI_TCPIPConfig_SubnetMask_SIZE sizeof(ISCSI_IP_Address)
    #define MSiSCSI_TCPIPConfig_SubnetMask_ID 7

    // Preferred DNS Server
    ISCSI_IP_Address PreferredDNSServer;
    #define MSiSCSI_TCPIPConfig_PreferredDNSServer_SIZE sizeof(ISCSI_IP_Address)
    #define MSiSCSI_TCPIPConfig_PreferredDNSServer_ID 8

    // Alternate DNS Server
    ISCSI_IP_Address AlternateDNSServer;
    #define MSiSCSI_TCPIPConfig_AlternateDNSServer_SIZE sizeof(ISCSI_IP_Address)
    #define MSiSCSI_TCPIPConfig_AlternateDNSServer_ID 9

} MSiSCSI_TCPIPConfig, *PMSiSCSI_TCPIPConfig;

#define MSiSCSI_TCPIPConfig_SIZE (FIELD_OFFSET(MSiSCSI_TCPIPConfig, AlternateDNSServer) + MSiSCSI_TCPIPConfig_AlternateDNSServer_SIZE)

// MSiSCSI_NICConfig - MSiSCSI_NICConfig

//
// This class is optional.
//
// NIC Port configuration class, implement one instance for each physical 
// network interface port on your adapter.
//
// This class uses PDO instance names with 1 instance for each physical
// network interface port on your adapter.
//

typedef enum 
{
    ISCSI_NIC_LINKSTATE_DISCONNECTED = 0,
    ISCSI_NIC_LINKSTATE_CONNECTED = 1
} ISCSI_NIC_LINKSTATE, *PISCSI_NIC_LINKSTATE;

#define MSiSCSI_NICConfigGuid \
    { 0xc75258e9,0xbe79,0x4a48, { 0xa2,0x3d,0xee,0xb6,0xf8,0xfb,0x94,0x0c } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(MSiSCSI_NICConfig_GUID, \
            0xc75258e9,0xbe79,0x4a48,0xa2,0x3d,0xee,0xb6,0xf8,0xfb,0x94,0x0c);
#endif


typedef struct _MSiSCSI_NICConfig
{
    // Speed of network link in megabits per second.
    ULONG LinkSpeed;
    #define MSiSCSI_NICConfig_LinkSpeed_SIZE sizeof(ULONG)
    #define MSiSCSI_NICConfig_LinkSpeed_ID 1

    // Maximum Speed of network link in megabits per second.
    ULONG MaxLinkSpeed;
    #define MSiSCSI_NICConfig_MaxLinkSpeed_SIZE sizeof(ULONG)
    #define MSiSCSI_NICConfig_MaxLinkSpeed_ID 2

    // Link State **typedef**
    ULONG LinkState;
    #define MSiSCSI_NICConfig_LinkState_SIZE sizeof(ULONG)
    #define MSiSCSI_NICConfig_LinkState_ID 3

    // Maximum frame size
    ULONG MaxFrameSize;
    #define MSiSCSI_NICConfig_MaxFrameSize_SIZE sizeof(ULONG)
    #define MSiSCSI_NICConfig_MaxFrameSize_ID 4

    // Ethernet MAC Address
    UCHAR MacAddress[6];
    #define MSiSCSI_NICConfig_MacAddress_SIZE sizeof(UCHAR[6])
    #define MSiSCSI_NICConfig_MacAddress_ID 5

} MSiSCSI_NICConfig, *PMSiSCSI_NICConfig;

#define MSiSCSI_NICConfig_SIZE (FIELD_OFFSET(MSiSCSI_NICConfig, MacAddress) + MSiSCSI_NICConfig_MacAddress_SIZE)

// MSiSCSI_BootConfiguration - MSiSCSI_BootConfiguration

//
// This class is optional.
//
// This class exposes the boot configuration if the adapter is configured to
// boot from an iSCSI disk.
//
// This class uses PDO instance names with a single instance.
//

#define MSiSCSI_BootConfigurationGuid \
    { 0x53ef8d5f,0x36f3,0x4124, { 0x8b,0x76,0xc6,0xad,0x52,0x1a,0x10,0x21 } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(MSiSCSI_BootConfiguration_GUID, \
            0x53ef8d5f,0x36f3,0x4124,0x8b,0x76,0xc6,0xad,0x52,0x1a,0x10,0x21);
#endif


typedef struct _MSiSCSI_BootConfiguration
{
    // LUN on target to use as boot device.
    ULONGLONG LUN;
    #define MSiSCSI_BootConfiguration_LUN_SIZE sizeof(ULONGLONG)
    #define MSiSCSI_BootConfiguration_LUN_ID 1

    // Security flags
    ULONGLONG SecurityFlags;
    #define MSiSCSI_BootConfiguration_SecurityFlags_SIZE sizeof(ULONGLONG)
    #define MSiSCSI_BootConfiguration_SecurityFlags_ID 2

    // Size in bytes of Target Username.
    ULONG UsernameSize;
    #define MSiSCSI_BootConfiguration_UsernameSize_SIZE sizeof(ULONG)
    #define MSiSCSI_BootConfiguration_UsernameSize_ID 3

    // Size in bytes of Target Password.
    ULONG PasswordSize;
    #define MSiSCSI_BootConfiguration_PasswordSize_SIZE sizeof(ULONG)
    #define MSiSCSI_BootConfiguration_PasswordSize_ID 4

    // If TRUE dynamically discover boot device.
    BOOLEAN DiscoverBootDevice;
    #define MSiSCSI_BootConfiguration_DiscoverBootDevice_SIZE sizeof(BOOLEAN)
    #define MSiSCSI_BootConfiguration_DiscoverBootDevice_ID 5

    // The InitiatorNode specifies the iSCSI name of the initiator node to use for the connection. If empty, then the adapter can choose any initiator node name.
    WCHAR InitiatorNode[223 + 1];
    #define MSiSCSI_BootConfiguration_InitiatorNode_ID 6

    // TargetName specifies the iSCSI target name on which the boot device resides.
    WCHAR TargetName[223 + 1];
    #define MSiSCSI_BootConfiguration_TargetName_ID 7

    // Target portal to use for connection to the target.
    ISCSI_TargetPortal TargetPortal;
    #define MSiSCSI_BootConfiguration_TargetPortal_SIZE sizeof(ISCSI_TargetPortal)
    #define MSiSCSI_BootConfiguration_TargetPortal_ID 8

    // Options that affect how login is performed. See ISCSI_LoginOptions
    ISCSI_LoginOptions LoginOptions;
    #define MSiSCSI_BootConfiguration_LoginOptions_SIZE sizeof(ISCSI_LoginOptions)
    #define MSiSCSI_BootConfiguration_LoginOptions_ID 9

    // **extra fields** Authentication Username, for CHAP this is the CHAP Name (CHAP_N) use when authenticating with the target. NOTE: This field is a variable length array, the field that follows this field starts immediately after the end of this field subject to appropriate padding.
    UCHAR Username[1];
    #define MSiSCSI_BootConfiguration_Username_ID 10

    // Authentication Password, for CHAP this is the shared secret to use when generating the response to the target challange. This field is a variable length array.
//  UCHAR Password[1];
    #define MSiSCSI_BootConfiguration_Password_ID 11

} MSiSCSI_BootConfiguration, *PMSiSCSI_BootConfiguration;

// MSiSCSI_SecurityCapabilities - MSiSCSI_SecurityCapabilities

//
// This class is required if adapter supports IPSEC.
//
// This class exposes the security capabilities if the adapter 
// supports IPSEC.
//
// This class uses PDO instance names with a single instance.
//
typedef enum {
    ISCSI_ENCRYPT_NONE = 0,
    ISCSI_ENCRYPT_3DES_HMAC_SHA1 = 1,
    ISCSI_ENCRYPT_AES_CTR = 2              
} ISCSI_ENCRYPTION_TYPES, *PISCSI_ENCRYPTION_TYPES;


#define MSiSCSI_SecurityCapabilitiesGuid \
    { 0x225b9d64,0x47a9,0x41c8, { 0x81,0xcd,0x69,0xbc,0x02,0x65,0x2d,0x87 } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(MSiSCSI_SecurityCapabilities_GUID, \
            0x225b9d64,0x47a9,0x41c8,0x81,0xcd,0x69,0xbc,0x02,0x65,0x2d,0x87);
#endif


typedef struct _MSiSCSI_SecurityCapabilities
{
    // TRUE if the adapter can use IPSEC to protect iSCSI traffic.
    BOOLEAN ProtectiScsiTraffic;
    #define MSiSCSI_SecurityCapabilities_ProtectiScsiTraffic_SIZE sizeof(BOOLEAN)
    #define MSiSCSI_SecurityCapabilities_ProtectiScsiTraffic_ID 1

    // TRUE if the adapter can use IPSEC to protect iSNS traffic.
    BOOLEAN ProtectiSNSTraffic;
    #define MSiSCSI_SecurityCapabilities_ProtectiSNSTraffic_SIZE sizeof(BOOLEAN)
    #define MSiSCSI_SecurityCapabilities_ProtectiSNSTraffic_ID 2

    // TRUE if adapter supports certificates
    BOOLEAN CertificatesSupported;
    #define MSiSCSI_SecurityCapabilities_CertificatesSupported_SIZE sizeof(BOOLEAN)
    #define MSiSCSI_SecurityCapabilities_CertificatesSupported_ID 3

    // Number of encryption types available.
    ULONG EncryptionAvailableCount;
    #define MSiSCSI_SecurityCapabilities_EncryptionAvailableCount_SIZE sizeof(ULONG)
    #define MSiSCSI_SecurityCapabilities_EncryptionAvailableCount_ID 4

    // **typedef** Array of encryption types. This field is a variable length array.
    ULONG EncryptionAvailable[1];
    #define MSiSCSI_SecurityCapabilities_EncryptionAvailable_ID 5

} MSiSCSI_SecurityCapabilities, *PMSiSCSI_SecurityCapabilities;

// MSiSCSI_DiscoveryConfig - MSiSCSI_DiscoveryConfig

//
// This class is required.
//
// This class exposes the configuration capabilities for the adapter to be able to
// perform target discovery. An adapter needs to support target discovery
// if it is ever placed on a separate network from the PC NIC. Although
// the iSCSI Initiator service can use this class with any discovery mechanism
// the best results are obtained by using iSNS.
//
// This class uses PDO instance names with a single instance.
//

#define MSiSCSI_DiscoveryConfigGuid \
    { 0x45755098,0x4291,0x43df, { 0x97,0x20,0xb5,0x86,0x42,0xdd,0x63,0xdf } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(MSiSCSI_DiscoveryConfig_GUID, \
            0x45755098,0x4291,0x43df,0x97,0x20,0xb5,0x86,0x42,0xdd,0x63,0xdf);
#endif


typedef struct _MSiSCSI_DiscoveryConfig
{
    // TRUE if adapter should perform target discovery via iSNS.
    BOOLEAN PerformiSNSDiscovery;
    #define MSiSCSI_DiscoveryConfig_PerformiSNSDiscovery_SIZE sizeof(BOOLEAN)
    #define MSiSCSI_DiscoveryConfig_PerformiSNSDiscovery_ID 1

    // TRUE if adapter should perform target discovery via SLP.
    BOOLEAN PerformSLPDiscovery;
    #define MSiSCSI_DiscoveryConfig_PerformSLPDiscovery_SIZE sizeof(BOOLEAN)
    #define MSiSCSI_DiscoveryConfig_PerformSLPDiscovery_ID 2

    // TRUE if adapter should perform automatic discovery of iSNS server.
    BOOLEAN AutomaticiSNSDiscovery;
    #define MSiSCSI_DiscoveryConfig_AutomaticiSNSDiscovery_SIZE sizeof(BOOLEAN)
    #define MSiSCSI_DiscoveryConfig_AutomaticiSNSDiscovery_ID 3

    // Default initiator name for registering with iSNS.
    WCHAR InitiatorName[256 + 1];
    #define MSiSCSI_DiscoveryConfig_InitiatorName_ID 4

    // If AutomaticiSNSDiscovery is FALSE then this contains the fixed addresses of iSNS servers
    ISCSI_IP_Address iSNSServer;
    #define MSiSCSI_DiscoveryConfig_iSNSServer_SIZE sizeof(ISCSI_IP_Address)
    #define MSiSCSI_DiscoveryConfig_iSNSServer_ID 5

} MSiSCSI_DiscoveryConfig, *PMSiSCSI_DiscoveryConfig;

#define MSiSCSI_DiscoveryConfig_SIZE (FIELD_OFFSET(MSiSCSI_DiscoveryConfig, iSNSServer) + MSiSCSI_DiscoveryConfig_iSNSServer_SIZE)

// MSiSCSI_RADIUSConfig - MSiSCSI_RADIUSConfig

//
// This class is required if adapter supports using RADIUS for CHAP authentication.
//
// This class exposes the configuration capabilities if the adapter able to
// use radius to perform CHAP authentication. Using RADIUS is encouraged
// since it allows centralized management of CHAP credentials.
//
// This class uses PDO instance names with a single instance.
//

#define MSiSCSI_RADIUSConfigGuid \
    { 0x8eaef9d8,0xc053,0x49d3, { 0x92,0x05,0x65,0xc7,0x03,0xc2,0xec,0xc1 } }

#if ! (defined(MIDL_PASS))
DEFINE_GUID(MSiSCSI_RADIUSConfig_GUID, \
            0x8eaef9d8,0xc053,0x49d3,0x92,0x05,0x65,0xc7,0x03,0xc2,0xec,0xc1);
#endif


typedef struct _MSiSCSI_RADIUSConfig
{
    // TRUE if adapter should use RADIUS for CHAP authentication
    BOOLEAN UseRADIUSForCHAP;
    #define MSiSCSI_RADIUSConfig_UseRADIUSForCHAP_SIZE sizeof(BOOLEAN)
    #define MSiSCSI_RADIUSConfig_UseRADIUSForCHAP_ID 1

    // Size in bytes of shared secret used to communicate with RADIUS servers
    ULONG SharedSecretSizeInBytes;
    #define MSiSCSI_RADIUSConfig_SharedSecretSizeInBytes_SIZE sizeof(ULONG)
    #define MSiSCSI_RADIUSConfig_SharedSecretSizeInBytes_ID 2

    // Fixed address of primary RADIUS server
    ISCSI_IP_Address RADIUSServer;
    #define MSiSCSI_RADIUSConfig_RADIUSServer_SIZE sizeof(ISCSI_IP_Address)
    #define MSiSCSI_RADIUSConfig_RADIUSServer_ID 3

    // Fixed address of backup RADIUS server
    ISCSI_IP_Address BackupRADIUSServer;
    #define MSiSCSI_RADIUSConfig_BackupRADIUSServer_SIZE sizeof(ISCSI_IP_Address)
    #define MSiSCSI_RADIUSConfig_BackupRADIUSServer_ID 4

    // Must be zero
    ULONG Reserved;
    #define MSiSCSI_RADIUSConfig_Reserved_SIZE sizeof(ULONG)
    #define MSiSCSI_RADIUSConfig_Reserved_ID 5

    // Shared secret for communicating with primary and backup RADIUS servers. This field is a variable length array.
    UCHAR SharedSecret[1];
    #define MSiSCSI_RADIUSConfig_SharedSecret_ID 6

} MSiSCSI_RADIUSConfig, *PMSiSCSI_RADIUSConfig;

#endif
