#include <iostream>
#include <cstring>

#include "soapDeviceBindingProxy.h"
#include "DeviceBinding.nsmap"


int main(int argc, const char * argv[])
{
    struct soap soap;

    soap_init( &soap );

    DeviceBindingProxy proxy( &soap );    

    _tds__GetDeviceInformation tds__GetDeviceInformation;
    _tds__GetDeviceInformationResponse tds__GetDeviceInformationResponse;

    std::string endpoint = "http://192.168.0.99/onvif/services";

    int result = SOAP_ERR;    

    result = proxy.GetDeviceInformation( endpoint.c_str(), NULL, &tds__GetDeviceInformation, tds__GetDeviceInformationResponse );

    if ( result == SOAP_OK )
    {
        std::cout << "Mfr: " << tds__GetDeviceInformationResponse.Manufacturer << std::endl;
        std::cout << "Model: " << tds__GetDeviceInformationResponse.Model << std::endl;
        std::cout << "F/W version: " << tds__GetDeviceInformationResponse.FirmwareVersion << std::endl;
    }

    return 0;
}

