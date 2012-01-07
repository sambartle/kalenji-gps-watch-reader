#ifndef _SOURCE_USB_HPP_
#define _SOURCE_USB_HPP_

#include <libusb.h>
#include <string>
#include "Source.h"

#define RESPONSE_BUFFER_SIZE 4096

namespace source
{
	/**
	  A class to handle sending and receiving data through USB
	 */
	class USB : public Source
	{
		public:
			// TODO: configurable timeout ?
			USB() : _timeout(5000) { };
			~USB() {};

			/** 
			  Initialize the source. Any action that needs to be taken before using the source.
			 */ 
			virtual void init(uint32_t vendorId, uint32_t productId);

			/** 
			  Release the source. Any action that needs to be taken once the source is not needed anymore.
			 */ 
			virtual void release();

			/** 
			  Read data from source. Handle associated memory. 
			  @param oData Address of a pointer that will be set to point to read data after the call
			  @param oLength Address of a variable that will contain the size of the data after the call
			 */ 
			virtual void read_data(unsigned char **oData, size_t *oLength);
			/** 
			  Send data to the source. 
			  @param iData A pointer to data to be sent
			  @param iLength Size of the data to be sent
			 */ 
			virtual void write_data(unsigned char *iData, size_t iLength);

			virtual std::string getName() { return "USB"; };

		protected:
			bool checkUSBOperation(int rc);

		protected:
			libusb_device_handle *_device;

			uint32_t _timeout;
			unsigned char _responseData[4096];
			int transferred;
	};
}

#endif
