#ifndef __BOOST_SERIALIZE_H
#define __BOOST_SERIALIZE_H
#include<iostream>
#include<sstream>
#include<string>
using namespace std;

#include<boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>

class someip

{

private:

       friend class boost::serialization::access;
       
        uint32_t mid;
	uint32_t leng;
	uint32_t rid;
	uint8_t protocol_version;
	uint8_t interface_version;
	uint8_t message_type;
	uint8_t return_code;
	std::vector <int> payload;
       

       template<class Archive>

       void serialize(Archive& , const unsigned int);

public:

       someip()
       {

       }

       someip(uint32_t m, uint32_t l, uint32_t r, uint8_t p_v,uint8_t i_v, uint8_t m_t, uint8_t r_c, std::vector <int> p) :mid(m), leng(l), rid(r), protocol_version(p_v), interface_version(i_v), message_type(m_t), return_code(r_c), payload(p)
       {

             

       }

       void showData();
       void save(ostream &);
       void load(string);

       ~someip()
       {
       
       }

};

#endif 

	
	
	

