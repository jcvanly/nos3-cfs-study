#ifndef NOS3_CLIENTDATAPROVIDER_HPP
#define NOS3_CLIENTDATAPROVIDER_HPP

#include <boost/property_tree/xml_parser.hpp>
#include <ItcLogger/Logger.hpp>
#include <client_data_point.hpp>
#include <sim_i_data_provider.hpp>

namespace Nos3
{
    class ClientDataProvider : public SimIDataProvider
    {
    public:
        /* Constructors */
        ClientDataProvider(const boost::property_tree::ptree& config);

        /* Accessors */
        boost::shared_ptr<SimIDataPoint> get_data_point(void) const;

    private:
        /* Disallow these */
        ~ClientDataProvider(void) {};
        ClientDataProvider& operator=(const ClientDataProvider&) {return *this;};

        mutable double _request_count;
    };
}

#endif
