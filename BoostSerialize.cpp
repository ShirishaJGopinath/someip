#include "BoostSerialize.h"

template<class Archive>

void someip::serialize(Archive& archive, const unsigned int version)
{            
              
        archive & mid;
	archive & leng;
	archive & rid;
	archive & protocol_version;
	archive & interface_version;
	archive & message_type;
	archive & return_code;
	archive & payload;

}

void someip::showData()
{
              cout<<"mid:"<<mid<<endl;
              cout<<"leng:"<<leng<<endl;
              cout<<"rid:"<<rid<<endl;
              cout<<"protocol_version:"<<protocol_version<<endl;
              cout<<"interface_version:"<<interface_version<<endl;
              cout<<"message_type:"<<message_type<<endl;
              cout<<"return_code:"<<return_code<<endl;
              cout<<"Payload:"<<endl;
              int size=payload.size();
              for(int i=0;i<size;i++)
              cout<<payload[i]<<endl;
}

void someip::save(ostream &oss)
{
              boost::archive::binary_oarchive oa(oss);
              oa & *(this);
}

void someip::load(string str_data)
{
              std::istringstream iss(str_data);
              boost::archive::binary_iarchive ia(iss);
              ia & *(this);
}

BOOST_CLASS_VERSION(someip, 1)

 

 

	
	
	

