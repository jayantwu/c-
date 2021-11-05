#include<iostream>
#include<sstream>
#include<array>
#include<iomanip>
    struct clx_mac_s {
        enum : uint32_t {MAC_LEN = 6};

        std::string                  m_name;  //< mac 
        std::array<uint8_t, MAC_LEN> m_value; //< 48-bits mac

        clx_mac_s() = default;
        clx_mac_s(const uint64_t & v, const std::string & name = "mac")
        : m_name(name)  {
            for (auto idx = 0; idx < MAC_LEN; idx ++)
                m_value[idx] = (v >> (40 - 8*idx)) & 0xff;
        }

        /// @brief stringify mac
        /// @param[in] sep - seperator ":" in default
        /// @return return string
        std::string str(const std::string &sep = ":") const
        {
            std::ostringstream ss;
            for (auto idx = 0; idx < MAC_LEN; idx++)
            {
                ss 
                << std::setfill('0') 
                << std::setw(2)
                <<std::hex 
                << (m_value[idx] & 0xff);

                if (idx < (MAC_LEN - 1))
                    ss << sep;
            }
            return ss.str();
        }

        /// @brief friendly implement <<
        friend std::ostream& operator<<(std::ostream& os, const clx_mac_s& a) {
            return os << a.str();
        }

    };


    int main()
    {
        clx_mac_s mac(0x22334455);
        std::cout << mac << std::endl;
        std::cout << mac.str("-") << std::endl;

    }