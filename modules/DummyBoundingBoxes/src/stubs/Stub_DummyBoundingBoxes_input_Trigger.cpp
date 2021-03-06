// auto-generated header by CodeFromTemplate - Connected Vision - https://github.com/ConnectedVision
// CodeFromTemplate Version: 0.3 alpha
// stubs/Stub_DummyBoundingBoxes_input_Trigger.cpp
// NEVER TOUCH this file!

#include <utility>

#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/error/en.h>
#include <boost/make_shared.hpp>

#include "Stub_DummyBoundingBoxes_input_Trigger.h"
#include "../Class_DummyBoundingBoxes_input_Trigger.h"

// --> Do NOT EDIT <--
namespace ConnectedVision {
namespace Module {
namespace DummyBoundingBoxes {




// --> Do NOT EDIT <--
/* copy constructors */
Stub_DummyBoundingBoxes_input_Trigger::Stub_DummyBoundingBoxes_input_Trigger(const Stub_DummyBoundingBoxes_input_Trigger& other)
{
	// TODO: other.readLock
	// id
	id = other.id;
	// configID
	configID = other.configID;
	// timestamp
	timestamp = other.timestamp;
}

// --> Do NOT EDIT <--
/* copy assignment operator */
Stub_DummyBoundingBoxes_input_Trigger& Stub_DummyBoundingBoxes_input_Trigger::operator =(const Stub_DummyBoundingBoxes_input_Trigger& other)
{
	Stub_DummyBoundingBoxes_input_Trigger tmp(other); // re-use copy-constructor
	*this = std::move(tmp); // re-use move-assignment
	return *this;
}

// --> Do NOT EDIT <--
/* mopy assignment operator */
Stub_DummyBoundingBoxes_input_Trigger& Stub_DummyBoundingBoxes_input_Trigger::operator =(Stub_DummyBoundingBoxes_input_Trigger&& other) noexcept
{
	// id
    std::swap(id, other.id);
	// configID
    std::swap(configID, other.configID);
	// timestamp
    std::swap(timestamp, other.timestamp);

	return *this;
}

// --> Do NOT EDIT <--
/* default constructors */
Stub_DummyBoundingBoxes_input_Trigger::Stub_DummyBoundingBoxes_input_Trigger()
{
	clear();
}

// --> Do NOT EDIT <--
Stub_DummyBoundingBoxes_input_Trigger::Stub_DummyBoundingBoxes_input_Trigger(const rapidjson::Value& value)
{
	clear();
	parseJson( value );
}

// --> Do NOT EDIT <--
Stub_DummyBoundingBoxes_input_Trigger::Stub_DummyBoundingBoxes_input_Trigger(const std::string& str)
{
	clear();
	parseJson( str );
}

// --> Do NOT EDIT <--
Stub_DummyBoundingBoxes_input_Trigger::~Stub_DummyBoundingBoxes_input_Trigger()
{
}

// --> Do NOT EDIT <--
void Stub_DummyBoundingBoxes_input_Trigger::clear()
{
	this->id = "";
	this->configID = "";
	this->timestamp = 0;
}

// --> Do NOT EDIT <--
void Stub_DummyBoundingBoxes_input_Trigger::parseJson(const char *str)
{
	// ignore empty data
	if ( str[0] == 0 )
		return;
	
	// parse data
	rapidjson::Document document;
	if (document.Parse<0>(str).HasParseError())
	{
		std::string context;
		size_t off = document.GetErrorOffset();
		size_t i, line_start = 0, context_start = 0;
		int num_line = 1;
		for ( i = 0; (i < off) && str[i]; i++ )
		{
			if ( str[i] == '\n' )
			{ line_start = i+1; context_start = i+1; num_line++; }
			if ( str[i] == '{' || str[i] == '[' )
			{ context_start = i; }
		}
		for ( i = context_start; str[i]; i++ )
		{
			if ( str[i] == '\n' || str[i] == '\r' ) break;
			context += str[i];
			if ( str[i] == '}' || str[i] == ']' ) break;
		}
		throw ConnectedVision::runtime_error( std::string("parse error of JSON Object: ") + rapidjson::GetParseError_En(document.GetParseError()) + std::string(" at line ") + ConnectedVision::intToStr( num_line ) + ": " + context);
	}

	parseJson(document);
}

// --> Do NOT EDIT <--
void Stub_DummyBoundingBoxes_input_Trigger::parseJson(const rapidjson::Value& value)
{
	clear();
	if ( !value.IsObject() )
		throw ConnectedVision::runtime_error( "no JSON Object");

	// id
	if ((value.HasMember("id")) && value["id"].IsString())
	{
		set_id( ConnectedVision::strToID( value["id"].GetString() ) );
	}
	else
		throw ConnectedVision::runtime_error( "required member is missing: 'id'");

	// configID
	if ((value.HasMember("configID")) && value["configID"].IsString())
	{
		set_configID( ConnectedVision::strToID( value["configID"].GetString() ) );
	}
	else
		throw ConnectedVision::runtime_error( "required member is missing: 'configID'");

	// timestamp
	if ((value.HasMember("timestamp")) && value["timestamp"].IsInt64())
	{
		set_timestamp( value["timestamp"].GetInt64() );
	}
	else
		throw ConnectedVision::runtime_error( "required member is missing: 'timestamp'");

}

// --> Do NOT EDIT <--
std::string Stub_DummyBoundingBoxes_input_Trigger::toJsonStr() const
{
	rapidjson::StringBuffer s;
	rapidjson::Document doc; doc.SetObject();
	this->toJson(doc, doc.GetAllocator());
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(s);
	doc.Accept(writer);
	return std::string(s.GetString());
}

// --> Do NOT EDIT <--
std::string Stub_DummyBoundingBoxes_input_Trigger::toJson() const
{
	rapidjson::StringBuffer s;
	rapidjson::Document doc; doc.SetObject();
	this->toJson(doc, doc.GetAllocator());
	rapidjson::Writer<rapidjson::StringBuffer> writer(s);
	doc.Accept(writer);
	return std::string(s.GetString());
}

// --> Do NOT EDIT <--
rapidjson::Value& Stub_DummyBoundingBoxes_input_Trigger::toJson(rapidjson::Value& node, rapidjson::Value::AllocatorType& allocator) const
{
	{ // id
		node.AddMember("id", rapidjson::Value().SetString( ConnectedVision::IDToChar( get_id() ), allocator), allocator);
	}
	{ // configID
		node.AddMember("configID", rapidjson::Value().SetString( ConnectedVision::IDToChar( get_configID() ), allocator), allocator);
	}
	{ // timestamp
		node.AddMember("timestamp", rapidjson::Value().SetInt64( get_timestamp() ), allocator);
	}
	return node;
}

// --> Do NOT EDIT <--
ConnectedVision::id_t Stub_DummyBoundingBoxes_input_Trigger::get_id() const
{
	return( this->id );
}

// --> Do NOT EDIT <--
const ConnectedVision::id_t Stub_DummyBoundingBoxes_input_Trigger::getconst_id() const
{
	return( this->id );
}

// --> Do NOT EDIT <--
void Stub_DummyBoundingBoxes_input_Trigger::set_id(ConnectedVision::id_t value)
{
	this->id = value;
}

// --> Do NOT EDIT <--
ConnectedVision::id_t Stub_DummyBoundingBoxes_input_Trigger::get_configID() const
{
	return( this->configID );
}

// --> Do NOT EDIT <--
const ConnectedVision::id_t Stub_DummyBoundingBoxes_input_Trigger::getconst_configID() const
{
	return( this->configID );
}

// --> Do NOT EDIT <--
void Stub_DummyBoundingBoxes_input_Trigger::set_configID(ConnectedVision::id_t value)
{
	this->configID = value;
}

// --> Do NOT EDIT <--
ConnectedVision::timestamp_t Stub_DummyBoundingBoxes_input_Trigger::get_timestamp() const
{
	return( this->timestamp );
}

// --> Do NOT EDIT <--
const ConnectedVision::timestamp_t Stub_DummyBoundingBoxes_input_Trigger::getconst_timestamp() const
{
	return( this->timestamp );
}

// --> Do NOT EDIT <--
void Stub_DummyBoundingBoxes_input_Trigger::set_timestamp(ConnectedVision::timestamp_t value)
{
	this->timestamp = value;
}


} // namespace DummyBoundingBoxes
} // namespace Module
} // namespace ConnectedVision