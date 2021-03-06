// auto-generated header by CodeFromTemplate - Connected Vision - https://github.com/ConnectedVision
// CodeFromTemplate Version: 0.3 alpha
// stubs/Stub_SyntheticVideo_output_FrameMetadata.cpp
// NEVER TOUCH this file!

#include <utility>

#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/error/en.h>
#include <boost/make_shared.hpp>

#include "Stub_SyntheticVideo_output_FrameMetadata.h"
#include "../Class_SyntheticVideo_output_FrameMetadata.h"

// --> Do NOT EDIT <--
namespace ConnectedVision {
namespace Module {
namespace SyntheticVideo {




// --> Do NOT EDIT <--
/* copy constructors */
Stub_SyntheticVideo_output_FrameMetadata::Stub_SyntheticVideo_output_FrameMetadata(const Stub_SyntheticVideo_output_FrameMetadata& other)
{
	// TODO: other.readLock
	// id
	id = other.id;
	// configID
	configID = other.configID;
	// timestamp
	timestamp = other.timestamp;
	// framenumber
	framenumber = other.framenumber;
	// width
	width = other.width;
	// height
	height = other.height;
}

// --> Do NOT EDIT <--
/* copy assignment operator */
Stub_SyntheticVideo_output_FrameMetadata& Stub_SyntheticVideo_output_FrameMetadata::operator =(const Stub_SyntheticVideo_output_FrameMetadata& other)
{
	Stub_SyntheticVideo_output_FrameMetadata tmp(other); // re-use copy-constructor
	*this = std::move(tmp); // re-use move-assignment
	return *this;
}

// --> Do NOT EDIT <--
/* mopy assignment operator */
Stub_SyntheticVideo_output_FrameMetadata& Stub_SyntheticVideo_output_FrameMetadata::operator =(Stub_SyntheticVideo_output_FrameMetadata&& other) noexcept
{
	// id
    std::swap(id, other.id);
	// configID
    std::swap(configID, other.configID);
	// timestamp
    std::swap(timestamp, other.timestamp);
	// framenumber
    std::swap(framenumber, other.framenumber);
	// width
    std::swap(width, other.width);
	// height
    std::swap(height, other.height);

	return *this;
}

// --> Do NOT EDIT <--
/* default constructors */
Stub_SyntheticVideo_output_FrameMetadata::Stub_SyntheticVideo_output_FrameMetadata()
{
	clear();
}

// --> Do NOT EDIT <--
Stub_SyntheticVideo_output_FrameMetadata::Stub_SyntheticVideo_output_FrameMetadata(const rapidjson::Value& value)
{
	clear();
	parseJson( value );
}

// --> Do NOT EDIT <--
Stub_SyntheticVideo_output_FrameMetadata::Stub_SyntheticVideo_output_FrameMetadata(const std::string& str)
{
	clear();
	parseJson( str );
}

// --> Do NOT EDIT <--
Stub_SyntheticVideo_output_FrameMetadata::~Stub_SyntheticVideo_output_FrameMetadata()
{
}

// --> Do NOT EDIT <--
void Stub_SyntheticVideo_output_FrameMetadata::clear()
{
	this->id = "";
	this->configID = "";
	this->timestamp = 0;
	this->framenumber = static_cast<int64_t>(0);
	this->width = static_cast<int64_t>(0);
	this->height = static_cast<int64_t>(0);
}

// --> Do NOT EDIT <--
void Stub_SyntheticVideo_output_FrameMetadata::parseJson(const char *str)
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
void Stub_SyntheticVideo_output_FrameMetadata::parseJson(const rapidjson::Value& value)
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

	// framenumber
	if ((value.HasMember("framenumber")) && value["framenumber"].IsInt64())
	{
		set_framenumber( value["framenumber"].GetInt64() );
	}
	else
		throw ConnectedVision::runtime_error( "required member is missing: 'framenumber'");

	// width
	if ((value.HasMember("width")) && value["width"].IsInt64())
	{
		set_width( value["width"].GetInt64() );
	}
	else
		throw ConnectedVision::runtime_error( "required member is missing: 'width'");

	// height
	if ((value.HasMember("height")) && value["height"].IsInt64())
	{
		set_height( value["height"].GetInt64() );
	}
	else
		throw ConnectedVision::runtime_error( "required member is missing: 'height'");

}

// --> Do NOT EDIT <--
std::string Stub_SyntheticVideo_output_FrameMetadata::toJsonStr() const
{
	rapidjson::StringBuffer s;
	rapidjson::Document doc; doc.SetObject();
	this->toJson(doc, doc.GetAllocator());
	rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(s);
	doc.Accept(writer);
	return std::string(s.GetString());
}

// --> Do NOT EDIT <--
std::string Stub_SyntheticVideo_output_FrameMetadata::toJson() const
{
	rapidjson::StringBuffer s;
	rapidjson::Document doc; doc.SetObject();
	this->toJson(doc, doc.GetAllocator());
	rapidjson::Writer<rapidjson::StringBuffer> writer(s);
	doc.Accept(writer);
	return std::string(s.GetString());
}

// --> Do NOT EDIT <--
rapidjson::Value& Stub_SyntheticVideo_output_FrameMetadata::toJson(rapidjson::Value& node, rapidjson::Value::AllocatorType& allocator) const
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
	{ // framenumber
		node.AddMember("framenumber", rapidjson::Value().SetInt64( get_framenumber() ), allocator);
	}
	{ // width
		node.AddMember("width", rapidjson::Value().SetInt64( get_width() ), allocator);
	}
	{ // height
		node.AddMember("height", rapidjson::Value().SetInt64( get_height() ), allocator);
	}
	return node;
}

// --> Do NOT EDIT <--
ConnectedVision::id_t Stub_SyntheticVideo_output_FrameMetadata::get_id() const
{
	return( this->id );
}

// --> Do NOT EDIT <--
const ConnectedVision::id_t Stub_SyntheticVideo_output_FrameMetadata::getconst_id() const
{
	return( this->id );
}

// --> Do NOT EDIT <--
void Stub_SyntheticVideo_output_FrameMetadata::set_id(ConnectedVision::id_t value)
{
	this->id = value;
}

// --> Do NOT EDIT <--
ConnectedVision::id_t Stub_SyntheticVideo_output_FrameMetadata::get_configID() const
{
	return( this->configID );
}

// --> Do NOT EDIT <--
const ConnectedVision::id_t Stub_SyntheticVideo_output_FrameMetadata::getconst_configID() const
{
	return( this->configID );
}

// --> Do NOT EDIT <--
void Stub_SyntheticVideo_output_FrameMetadata::set_configID(ConnectedVision::id_t value)
{
	this->configID = value;
}

// --> Do NOT EDIT <--
ConnectedVision::timestamp_t Stub_SyntheticVideo_output_FrameMetadata::get_timestamp() const
{
	return( this->timestamp );
}

// --> Do NOT EDIT <--
const ConnectedVision::timestamp_t Stub_SyntheticVideo_output_FrameMetadata::getconst_timestamp() const
{
	return( this->timestamp );
}

// --> Do NOT EDIT <--
void Stub_SyntheticVideo_output_FrameMetadata::set_timestamp(ConnectedVision::timestamp_t value)
{
	this->timestamp = value;
}

// --> Do NOT EDIT <--
int64_t Stub_SyntheticVideo_output_FrameMetadata::get_framenumber() const
{
	return( this->framenumber );
}

// --> Do NOT EDIT <--
const int64_t Stub_SyntheticVideo_output_FrameMetadata::getconst_framenumber() const
{
	return( this->framenumber );
}

// --> Do NOT EDIT <--
void Stub_SyntheticVideo_output_FrameMetadata::set_framenumber(int64_t value)
{
	this->framenumber = value;
}

// --> Do NOT EDIT <--
int64_t Stub_SyntheticVideo_output_FrameMetadata::get_width() const
{
	return( this->width );
}

// --> Do NOT EDIT <--
const int64_t Stub_SyntheticVideo_output_FrameMetadata::getconst_width() const
{
	return( this->width );
}

// --> Do NOT EDIT <--
void Stub_SyntheticVideo_output_FrameMetadata::set_width(int64_t value)
{
	this->width = value;
}

// --> Do NOT EDIT <--
int64_t Stub_SyntheticVideo_output_FrameMetadata::get_height() const
{
	return( this->height );
}

// --> Do NOT EDIT <--
const int64_t Stub_SyntheticVideo_output_FrameMetadata::getconst_height() const
{
	return( this->height );
}

// --> Do NOT EDIT <--
void Stub_SyntheticVideo_output_FrameMetadata::set_height(int64_t value)
{
	this->height = value;
}


} // namespace SyntheticVideo
} // namespace Module
} // namespace ConnectedVision