// auto-generated header by CodeFromTemplate - Connected Vision - https://github.com/ConnectedVision
// CodeFromTemplate Version: 0.3 alpha
// stubs/Store_SQLite_Stub_Skeleton_input_Detections.cpp
// NEVER TOUCH this file!

#include <exception>
#include <boost/assign/list_of.hpp>

#include "../Store_SQLite_Skeleton_input_Detections.h"

#include "Store_SQLite_Stub_Skeleton_input_Detections.h"

// --> Do NOT EDIT <--
namespace ConnectedVision {
namespace test {
namespace DataHandling {

//////////////////////////////////////////////////////////////////////////////
//
// Store_SQLite_Stub_Skeleton_input_Detections
//
//////////////////////////////////////////////////////////////////////////////

// --> Do NOT EDIT <--
static const std::string _tableName = "Skeleton_input_Detections";

// --> Do NOT EDIT <--
static const std::vector<std::string> _columnDesc = boost::assign::list_of
	("'_sortID' BIGINT NOT NULL DEFAULT '0' /* object sortable id () */")
	("'id' VARCHAR(32) NOT NULL DEFAULT '' /*  (string) */")
	("'configID' VARCHAR(32) NOT NULL DEFAULT '' /*  (string) */")
	("'objectID' VARCHAR(32) NOT NULL DEFAULT '' /*  (string) */")
	("'timestamp' BIGINT NOT NULL DEFAULT '0' /* first detection (integer) */")
	("'boundingBox.left' DOUBLE /* x position of top left point of the rectangle (number) */")
	("'boundingBox.right' DOUBLE /* x position of bottom right point of the rectangle (number) */")
	("'boundingBox.top' DOUBLE /* y position of top left point of the rectangle (number) */")
	("'boundingBox.bottom' DOUBLE /* y position of bottom right point of the rectangle (number) */")
;

// --> Do NOT EDIT <--
Store_SQLite_Stub_Skeleton_input_Detections::Store_SQLite_Stub_Skeleton_input_Detections(const id_t& configID, DBConnection& db) :
	Store_SQLite_BaseClass<Class_Skeleton_input_Detections>(configID, db, _tableName, _columnDesc)
{
}

// --> Do NOT EDIT <--
Store_SQLite_Stub_Skeleton_input_Detections::~Store_SQLite_Stub_Skeleton_input_Detections()
{
}

#ifdef ENABLE_SQLITE_SEARCH
// --> Do NOT EDIT <--
/**
 *  Get objects filtered by id
 */
std::vector<shared_ptr<const Class_Skeleton_input_Detections> > Store_SQLite_Stub_Skeleton_input_Detections::getBy_id(const ConnectedVision::id_t& val)
{
	std::vector< Store::FilterEntry > filterList;
	std::vector< Store::SortEntry > sortList;
	filterList.push_back( Store::FilterEntry("id", Store::Op::EQUAL, IDToStr(val) ) );
	return getByFilter(filterList, sortList);
}

// --> Do NOT EDIT <--
/**
 *  Get objects filtered by configID
 */
std::vector<shared_ptr<const Class_Skeleton_input_Detections> > Store_SQLite_Stub_Skeleton_input_Detections::getBy_configID(const ConnectedVision::id_t& val)
{
	std::vector< Store::FilterEntry > filterList;
	std::vector< Store::SortEntry > sortList;
	filterList.push_back( Store::FilterEntry("configID", Store::Op::EQUAL, IDToStr(val) ) );
	return getByFilter(filterList, sortList);
}

// --> Do NOT EDIT <--
/**
 *  Get objects filtered by objectID
 */
std::vector<shared_ptr<const Class_Skeleton_input_Detections> > Store_SQLite_Stub_Skeleton_input_Detections::getBy_objectID(const ConnectedVision::id_t& val)
{
	std::vector< Store::FilterEntry > filterList;
	std::vector< Store::SortEntry > sortList;
	filterList.push_back( Store::FilterEntry("objectID", Store::Op::EQUAL, IDToStr(val) ) );
	return getByFilter(filterList, sortList);
}

// --> Do NOT EDIT <--
/**
 *  Get objects filtered by timestamp
 */
std::vector<shared_ptr<const Class_Skeleton_input_Detections> > Store_SQLite_Stub_Skeleton_input_Detections::getBy_timestamp(const ConnectedVision::timestamp_t& val)
{
	std::vector< Store::FilterEntry > filterList;
	std::vector< Store::SortEntry > sortList;
	filterList.push_back( Store::FilterEntry("timestamp", Store::Op::EQUAL, val) );
	return getByFilter(filterList, sortList);
}

#endif

// --> Do NOT EDIT <--
int Store_SQLite_Stub_Skeleton_input_Detections::readObject(sqlite3_stmt *stmt, shared_ptr<const Class_Skeleton_input_Detections>& outObj, sqlite3 *db)
{
	int error = SQLITE_ROW;

	int64_t objSortID = sqlite3_column_int64(stmt, 0);
	int64_t sortID = objSortID;
	outObj.reset( new Class_Skeleton_input_Detections() );
	auto obj = this->create();

	while ( (error == SQLITE_ROW) && (sortID == objSortID) )
	{
		// process row
			// Skeleton_input_Detections_id -> ConnectedVision::id_t
  			if ( sqlite3_column_type(stmt, 1) != SQLITE_NULL )
  				obj->set_id( strToID( reinterpret_cast<const char *>(sqlite3_column_text(stmt,1) ) ) );
			// Skeleton_input_Detections_configID -> ConnectedVision::id_t
  			if ( sqlite3_column_type(stmt, 2) != SQLITE_NULL )
  				obj->set_configID( strToID( reinterpret_cast<const char *>(sqlite3_column_text(stmt,2) ) ) );
			// Skeleton_input_Detections_objectID -> ConnectedVision::id_t
  			if ( sqlite3_column_type(stmt, 3) != SQLITE_NULL )
  				obj->set_objectID( strToID( reinterpret_cast<const char *>(sqlite3_column_text(stmt,3) ) ) );
			// Skeleton_input_Detections_timestamp -> ConnectedVision::timestamp_t
  			if ( sqlite3_column_type(stmt, 4) != SQLITE_NULL )
  				obj->set_timestamp( sqlite3_column_int64(stmt,4) );
			// Skeleton_input_Detections_boundingBox -> Class_Skeleton_input_Detections_boundingBox
  			{
  				boost::shared_ptr<Class_Skeleton_input_Detections_boundingBox>&& o1 = obj->get_boundingBox(); // rvalue reference for const functions
  				if ( !o1 ) o1.reset( new Class_Skeleton_input_Detections_boundingBox );
				// Skeleton_input_Detections_boundingBox_left -> double
  				if ( sqlite3_column_type(stmt, 5) != SQLITE_NULL )
  					o1->set_left( sqlite3_column_double(stmt,5) );
				// Skeleton_input_Detections_boundingBox_right -> double
  				if ( sqlite3_column_type(stmt, 6) != SQLITE_NULL )
  					o1->set_right( sqlite3_column_double(stmt,6) );
				// Skeleton_input_Detections_boundingBox_top -> double
  				if ( sqlite3_column_type(stmt, 7) != SQLITE_NULL )
  					o1->set_top( sqlite3_column_double(stmt,7) );
				// Skeleton_input_Detections_boundingBox_bottom -> double
  				if ( sqlite3_column_type(stmt, 8) != SQLITE_NULL )
  					o1->set_bottom( sqlite3_column_double(stmt,8) );
  			}

		error = sqlite3_step(stmt);
		if ( error == SQLITE_ROW )
			sortID = sqlite3_column_int64(stmt, 0);
	}

	outObj = this->make_const(obj);
	return error;
}

// --> Do NOT EDIT <--
int Store_SQLite_Stub_Skeleton_input_Detections::writeObject(sqlite3_stmt *stmt, const shared_ptr<const Class_Skeleton_input_Detections>& obj, sqlite3 *db, const int64_t sortID)
{
	int error = 0;


		sqlite3_reset(stmt);
		sqlite3_clear_bindings(stmt);

		bind_Skeleton_input_Detections( stmt, obj, sortID );

		bind_boundingBox( stmt, obj->getconst_boundingBox(), sortID );
		// write object base data and sub objects
		error = sqlite3_step(stmt);
		if ( error != SQLITE_DONE )
			return error;
	return error;
}

// --> Do NOT EDIT <--
void Store_SQLite_Stub_Skeleton_input_Detections::bind_Skeleton_input_Detections(sqlite3_stmt *stmt, const boost::shared_ptr<const Class_Skeleton_input_Detections>& obj, const int64_t sortID) const
{
	sqlite3_bind_int64(stmt, 1, sortID );
	sqlite3_bind_text(stmt, 2, IDToChar(obj->getconst_id()), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 3, IDToChar(obj->getconst_configID()), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 4, IDToChar(obj->getconst_objectID()), -1, SQLITE_TRANSIENT);
	sqlite3_bind_int64(stmt, 5, obj->getconst_timestamp() );
	// object: boundingBox handled separately
}

// --> Do NOT EDIT <--
void Store_SQLite_Stub_Skeleton_input_Detections::bind_boundingBox(sqlite3_stmt *stmt, const boost::shared_ptr<const Class_Skeleton_input_Detections_boundingBox>& obj, const int64_t sortID) const
{
	sqlite3_bind_int64(stmt, 1, sortID );
  	sqlite3_bind_double(stmt, 6, obj->getconst_left() );
  	sqlite3_bind_double(stmt, 7, obj->getconst_right() );
  	sqlite3_bind_double(stmt, 8, obj->getconst_top() );
  	sqlite3_bind_double(stmt, 9, obj->getconst_bottom() );
}

// --> Do NOT EDIT <--
void Store_SQLite_Stub_Skeleton_input_Detections::appendObjectGrouping(std::vector< Store::SortEntry >& sortList) const
{
	sortList.push_back( Store::SortEntry ("_sortID", Store::Order::ASC) );
}

// --> Do NOT EDIT <--
/**
 *  append object internal sort criteria to list
 */
const std::string Store_SQLite_Stub_Skeleton_input_Detections::objectKey() const
{
	return std::string("_sortID");
}


//////////////////////////////////////////////////////////////////////////////
//
// Store_SQLite_Factory_Stub_Skeleton_input_Detections
//
//////////////////////////////////////////////////////////////////////////////

// --> Do NOT EDIT <--
Store_SQLite_Factory_Stub_Skeleton_input_Detections::Store_SQLite_Factory_Stub_Skeleton_input_Detections(DBConnection& db) :
	db(db)
{}

// --> Do NOT EDIT <--
Store_SQLite_Factory_Stub_Skeleton_input_Detections::~Store_SQLite_Factory_Stub_Skeleton_input_Detections()
{}

shared_ptr< ConnectedVision::DataHandling::IStore_ReadWrite<Class_Skeleton_input_Detections> > Store_SQLite_Factory_Stub_Skeleton_input_Detections::create(const id_t configID = ID_NULL)
{
#ifdef Store_SQLite_Factory_Skeleton_input_Detections_enabled
	return boost::dynamic_pointer_cast< ConnectedVision::DataHandling::IStore_ReadWrite<Class_Skeleton_input_Detections> > (make_shared< DataHandling::Store_SQLite_Skeleton_input_Detections >(configID, this->db));
#else
	return shared_ptr< ConnectedVision::DataHandling::IStore_ReadWrite<Class_Skeleton_input_Detections> >();
#endif
}


} // namespace DataHandling
} // namespace test
} // namespace ConnectedVision