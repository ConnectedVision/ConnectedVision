// auto-generated header by CodeFromTemplate - Connected Vision - https://github.com/ConnectedVision
// CodeFromTemplate Version: 0.3 alpha
// stubs/Store_SQLite_Stub_DummyBoundingBoxes_input_Trigger.h
// NEVER TOUCH this file!

#ifndef Store_SQLite_Stub_DummyBoundingBoxes_input_Trigger_def
#define Store_SQLite_Stub_DummyBoundingBoxes_input_Trigger_def

#include <stdint.h>
#include <string>
#include <vector>
#include <sqlite3.h>
#include <ConnectedVision.h>
#include <DBConnection.h>
#include <IStore.h>
#include <general.h>
#include <DataHandling/Store_SQLite_BaseClass.h>
#include <DataHandling/Store_Manager_Basic.h>

// include classes
#include "../Class_DummyBoundingBoxes_input_Trigger.h"

// --> Do NOT EDIT <--
namespace ConnectedVision {
namespace Module {
namespace DummyBoundingBoxes {
namespace DataHandling {

// --> Do NOT EDIT <--
/**
 * stub class for: Store_SQLite_DummyBoundingBoxes_input_Trigger
 *
 * module: DummyBoundingBoxes
 * description: Trigger pulse used as signal for the generation of a bounding box.
 */
class Store_SQLite_Stub_DummyBoundingBoxes_input_Trigger :
	public ConnectedVision::DataHandling::Store_SQLite_BaseClass<Class_DummyBoundingBoxes_input_Trigger>
{

public:
	/**
	* constructor
	*/
	Store_SQLite_Stub_DummyBoundingBoxes_input_Trigger(
		const id_t& configID,			///< [in] config ID
		DBConnection& db				///< [in] DB connection object
	);

	/**
	* virtual desctructor
	*/
	virtual ~Store_SQLite_Stub_DummyBoundingBoxes_input_Trigger();

#ifdef ENABLE_SQLITE_SEARCH
public:
	// additional search functions
	/**
	*  Get objects filtered by id
	*/
	virtual std::vector<shared_ptr<const Class_DummyBoundingBoxes_input_Trigger> > getBy_id(const ConnectedVision::id_t& val);
	/**
	*  Get objects filtered by configID
	*/
	virtual std::vector<shared_ptr<const Class_DummyBoundingBoxes_input_Trigger> > getBy_configID(const ConnectedVision::id_t& val);
	/**
	*  Get objects filtered by timestamp
	*/
	virtual std::vector<shared_ptr<const Class_DummyBoundingBoxes_input_Trigger> > getBy_timestamp(const ConnectedVision::timestamp_t& val);
#endif

protected:
	// internal functions

	/**
	* read Object from DB
	* @note This function is MANDATORY.
	*
	*	Read table colum fields to object member variables.
	*	Call sqlite3_step() to read all sub/child objects.
	*
	* @return SQLite return code
	*/
	virtual int readObject(
		sqlite3_stmt *stmt,							///< [in] pre-executed SQLite statement
		shared_ptr<const Class_DummyBoundingBoxes_input_Trigger>& outObj,	///< [out] data object read from DB
		sqlite3 *db									///< [in] SQLite DB object
	);

	/**
	* write Object to DB
	* @note This function is MANDATORY.
	*
	*	Bind object member variables to table colum fields.
	*	This function has to write the whole objects,
	*	i.e. ti has to loop over all sub/child object bind them and call sqlite3_step() for each row.
	*
	* @return SQLite return code
	*/
	virtual int writeObject(
		sqlite3_stmt *stmt,							///< [in] prepared SQLite statement
		const shared_ptr<const Class_DummyBoundingBoxes_input_Trigger>& obj,	///< [in] data object read from DB
		sqlite3 *db,								///< [in] SQLite DB object
		const int64_t sortID						///< [in] unique index of object
	);

	/**
	* append object internal sort criteria to list
	* @note This function is MANDATORY.
	*/
	virtual void appendObjectGrouping(
		std::vector< Store::SortEntry >& sortList ///< [in/out] list of sort criteria for table rows
	) const;

	/**
	* get name of internal sort criteria column
	* @note This function is MANDATORY.
	*
	* @return column name
	*/
	virtual const std::string objectKey() const;

	// bind functions
	/**
	* bind object values for writing
	*/
	virtual void bind_DummyBoundingBoxes_input_Trigger(
		sqlite3_stmt *stmt, 							///< [in/out] SQLite statement to bind with
		const boost::shared_ptr<const Class_DummyBoundingBoxes_input_Trigger>& obj,					///< [in] data object read from DB
		const int64_t sortID	///< [in] sub array index to order sub items
	) const;
};

// --> Do NOT EDIT <--
/**
 * factory for: Store_SQLite_DummyBoundingBoxes_input_Trigger
 */
class Store_SQLite_Factory_Stub_DummyBoundingBoxes_input_Trigger :
	public ConnectedVision::DataHandling::IStore_ReadWrite_Factory<Class_DummyBoundingBoxes_input_Trigger>
{
public:
	/**
	* constructor
	*	uses DataAllocator_Primitive (new / delete for every object request)
	*/
	Store_SQLite_Factory_Stub_DummyBoundingBoxes_input_Trigger(
		DBConnection& db			///< [in] DB connection object
	);

	/**
	* virtual desctuctor
	*/
	virtual ~Store_SQLite_Factory_Stub_DummyBoundingBoxes_input_Trigger();

	/**
	* creates a new store
	*/
	virtual shared_ptr< ConnectedVision::DataHandling::IStore_ReadWrite<Class_DummyBoundingBoxes_input_Trigger> > create(
		const id_t configID			///< [in] config ID of requested store (optional)
	);

protected:
	DBConnection& db;
};

} // namespace DataHandling
} // namespace DummyBoundingBoxes
} // namespace Module
} // namespace ConnectedVision

#endif // Store_SQLite_Stub_DummyBoundingBoxes_input_Trigger_def