/*
 * Copyright (c) 1998-2003 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * Copyright (c) 1999-2003 Apple Computer, Inc.  All Rights Reserved.
 * 
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this
 * file.
 * 
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 * 
 * @APPLE_LICENSE_HEADER_END@
 */


#ifndef _IO_ATA_BLOCKSTORAGE_DEVICE_H_
#define _IO_ATA_BLOCKSTORAGE_DEVICE_H_

#include <IOKit/IOTypes.h>
#include <IOKit/ata/IOATACommand.h>
#include <IOKit/storage/IOBlockStorageDevice.h>

class IOATABlockStorageDriver_PD;

class IOATABlockStorageDevice : public IOBlockStorageDevice
{
	
	OSDeclareDefaultStructors ( IOATABlockStorageDevice )
	
	
protected:
	
	
	IOATABlockStorageDriver_PD *     fProvider;
	
	// binary compatibility instance variable expansion
	struct ExpansionData
	{
		OSSet *		fClients;
	};
	ExpansionData * reserved;
	
	#define fClients			reserved->fClients
	 
	virtual bool		attach ( IOService * provider ) APPLE_KEXT_OVERRIDE;
	virtual void        detach ( IOService * provider ) APPLE_KEXT_OVERRIDE;

    virtual bool		handleOpen ( IOService * client, IOOptionBits options, void * access ) APPLE_KEXT_OVERRIDE;
	virtual void		handleClose ( IOService * client, IOOptionBits options ) APPLE_KEXT_OVERRIDE;
    virtual bool		handleIsOpen ( const IOService * client ) const APPLE_KEXT_OVERRIDE;
	
public:
	
	//-----------------------------------------------------------------------
	// Override setProperties for turning off APM features on powerbooks.
	
    virtual IOReturn	setProperties ( OSObject * properties ) APPLE_KEXT_OVERRIDE;
	
	
    virtual IOReturn	doAsyncReadWrite ( 	IOMemoryDescriptor *buffer,
                                            UInt64 block, UInt64 nblks,
                                            IOStorageAttributes *attributes,
                                            IOStorageCompletion *completion ) APPLE_KEXT_OVERRIDE;

	virtual IOReturn	doSyncReadWrite ( 	IOMemoryDescriptor *	buffer,
											UInt32					block,
                                            UInt32					nblks );
	
    virtual IOReturn	doEjectMedia ( void ) APPLE_KEXT_OVERRIDE;
	
    virtual IOReturn	doFormatMedia ( UInt64 byteCapacity ) APPLE_KEXT_OVERRIDE;
	
    virtual UInt32		doGetFormatCapacities ( UInt64 *	capacities,
    											UInt32		capacitiesMaxCount ) const APPLE_KEXT_OVERRIDE;
	
    virtual IOReturn	doLockUnlockMedia ( bool doLock ) APPLE_KEXT_OVERRIDE ;
	
    virtual IOReturn	doSynchronizeCache ( void ) APPLE_KEXT_OVERRIDE ;
        
    virtual char *		getVendorString ( void ) APPLE_KEXT_OVERRIDE ;
    
    virtual char *		getProductString ( void ) APPLE_KEXT_OVERRIDE ;
    
    virtual char *		getRevisionString ( void ) APPLE_KEXT_OVERRIDE ;
    
    virtual char *		getAdditionalDeviceInfoString ( void ) APPLE_KEXT_OVERRIDE ;
    
    virtual IOReturn	reportBlockSize ( UInt64 * blockSize ) APPLE_KEXT_OVERRIDE ;
    
    virtual IOReturn	reportEjectability ( bool * isEjectable ) APPLE_KEXT_OVERRIDE ;
    
    virtual IOReturn	reportLockability ( bool * isLockable ) APPLE_KEXT_OVERRIDE ;
    
    virtual IOReturn	reportMediaState ( bool * mediaPresent, bool * changed ) APPLE_KEXT_OVERRIDE ;
    
    virtual IOReturn	reportPollRequirements ( 	bool * pollIsRequired,
    												bool * pollIsExpensive ) APPLE_KEXT_OVERRIDE;
    
    virtual IOReturn	reportMaxReadTransfer ( UInt64 blockSize, UInt64 * max );
    
    virtual IOReturn	reportMaxValidBlock ( UInt64 * maxBlock ) APPLE_KEXT_OVERRIDE;
    
    virtual IOReturn	reportMaxWriteTransfer ( UInt64 blockSize, UInt64 * max );
    
    virtual IOReturn	reportRemovability ( bool * isRemovable ) APPLE_KEXT_OVERRIDE;
    
    virtual IOReturn	reportWriteProtection ( bool * isWriteProtected ) APPLE_KEXT_OVERRIDE;
	
	virtual IOReturn	getWriteCacheState ( bool * enabled ) APPLE_KEXT_OVERRIDE;
	virtual IOReturn	setWriteCacheState ( bool enabled ) APPLE_KEXT_OVERRIDE;
	
private:
	/* Added with 10.1.4 */
	OSMetaClassDeclareReservedUsed ( IOATABlockStorageDevice, 1 )
	
	virtual IOReturn	sendSMARTCommand ( IOATACommand * command );
	
	// Binary Compatibility reserved method space
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 2 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 3 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 4 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 5 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 6 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 7 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 8 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 9 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 10 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 11 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 12 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 13 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 14 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 15 );
	OSMetaClassDeclareReservedUnused ( IOATABlockStorageDevice, 16 );
	
};

#endif /* !_IO_ATA_BLOCKSTORAGE_DEVICE_H_ */
