/*
# PostgreSQL Database Modeler (pgModeler)
#
# Copyright 2006-2022 - Raphael Araújo e Silva <raphael@pgmodeler.io>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation version 3.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# The complete text of GPLv3 is at LICENSE file on source code root directory.
# Also, you can get the complete GNU General Public License at <http://www.gnu.org/licenses/>
*/

/**
\ingroup libcore
\class Constraint
\brief Implements the operations to manipulate table constraints (primary keys, foreign key, unique and check).
\note <strong>Creation date:</strong> 17/09/2006
*/

#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "tableobject.h"
#include "tablespace.h"
#include "column.h"
#include "excludeelement.h"
#include "pgsqltypes/constrainttype.h"
#include "pgsqltypes/deferraltype.h"
#include "pgsqltypes/matchtype.h"
#include "pgsqltypes/actiontype.h"

class Constraint: public TableObject{
	private:
		//! \brief Type of the constraint (primary key, foreign key, unique or check)
		ConstraintType constr_type;

		//! \brief Indicates if the constraint is deferrable (except for check contraints)
		bool deferrable,

		//! \brief Indicates if the constraint will be copied or not to the child tables of the contraint's table (only for check constraint)
		no_inherit;

		//! \brief Deferral type for the constraint (except for check contraints)
		DeferralType deferral_type;

		//! \brief Matching method used by the constraint (only for foreign key)
		MatchType match_type;

		//! \brief Indexing type used by the constraint (only for exclude constraints)
		IndexingType index_type;

		/*! \brief This factor is used to indicate the space usage for the index generated by the constraint.
		 Generally there is no need do fill this attribute but for more refined tuning this can be set.
		 This is applicable only on primary keys and unique. */
		unsigned fill_factor;

		/*! \brief Actions taken when delete and update event occurs. This is applicable
		 only for foreign keys */
		ActionType del_action, upd_action;

		//! \brief Stores the columns that is referenced by the constraint (except for check constraints)
		std::vector<Column *> columns;

		//! \brief Stores the referenced columns from the referenced table primary key
		std::vector<Column *> ref_columns;

		//! \brief Stores the exclude elements of the exclude constraint
		std::vector<ExcludeElement> excl_elements;

		//! \brief Stores the check expression or the exclude predicate (only for check and exclude constraints)
		QString expression;

		//! \brief Stores the referenced table (only for foreign keys)
		BaseTable *ref_table;

		//! \brief Formats the string for constraint columns to be used by the SchemaParser
		void setColumnsAttribute(unsigned col_type, unsigned def_type, bool inc_addedbyrel=false);

		//! \brief Formats the exclude elements string used by the SchemaParser
		void setExcludeElementsAttribute(unsigned def_type);

		void setDeclInTableAttribute();

	protected:
		virtual void configureSearchAttributes();

	public:
		/*! \brief Access the source columns that means the columns that constrais
		is applied (from the constraint's parent table) */
		static constexpr unsigned SourceCols=0,

		/*! \brief Access the referenced columns that means the columns from the
														 referenced table primary key (only for foreign keys) */
		ReferencedCols=1;

		static constexpr unsigned DeleteAction=0,
		UpdateAction=1;

		Constraint();
		virtual ~Constraint();

		/*! \brief Adds one column to the internal column list referenced by the
		 constants SOURCE_COLS or REFERENCED_COLS */
		void addColumn(Column *column, unsigned col_type);

		/*! \brief Adds columns to the internal column list referenced by the
		 constants SOURCE_COLS or REFERENCED_COLS. Previously columns added are removed. */
		void addColumns(const std::vector<Column *> &cols, unsigned col_type);

		//! \brief Adds several elements to the constraint using a defined vector
		void addExcludeElements(std::vector<ExcludeElement> &elems);

		//! \brief Defines the constraint type
		void setConstraintType(ConstraintType constr_type);

		//! \brief Defines the type of action on foreign keys (ON DELETE and ON UPDATE). (only for foreign key)
		void setActionType(ActionType action_type, unsigned act_id);

		//! \brief Defines the deferral type for the constraint (except for check contraints)
		void setDeferralType(DeferralType deferral_type);

		//! \brief Defines whether the constraint is deferrable (except for check contraints)
		void setDeferrable(bool value);

		//! \brief Defines the matching type used by the constraint (only for foreign key)
		void setMatchType(MatchType constr_type);

		//! \brief Defines the indexing type used by the constraint (only for exclude)
		void setIndexType(IndexingType index_type);

		//! \brief Defines the expresion used by the constraint (only for check and exclude constraint)
		void setExpression(const QString &expr);

		//! \brief Defines the referenced table (only for foreign key)
		void setReferencedTable(BaseTable *tab_ref);

		//! \brief Defines the tablespace used by the constraint (only for primary keys and unique)
		void setTablespace(BaseObject *tabspc);

		/*! \brief Defines the constraint fill factor (only for primary keys and unique).
				Values less than 10 (except 0) or above 100 will be adjusted to accepted values. To use the default
				settings specify 0 as fill factor */
		void setFillFactor(unsigned factor);

		//! \brief Defines if the constraints is propagated to child tables (only for exclude constraints)
		void setNoInherit(bool value);

		//! \brief Returns the constraint fill factor
		unsigned getFillFactor();

		//! \brief Retuns the action type (ON DELETE or ON UPDATE) of a foreign key
		ActionType getActionType(unsigned act_id);

		//! \brief Returns the list of columns of the specified type SOURCE_COLS or REFERENCED_COLS
		std::vector<Column *> getColumns(unsigned col_type);

		/*! \brief Returns one column (using its index) from the internal constraint column lists.
		 Use the constants SOURCE_COLS or REFERENCED_COLS to access the lists */
		Column *getColumn(unsigned col_idx, unsigned col_type);

		/*! \brief Returns one column (using its name) from the internal constraint column lists.
		 Use the constants SOURCE_COLS or REFERENCED_COLS to access the lists */
		Column *getColumn(const QString &name, unsigned col_type);

		/*! \brief Returns the column count for one internal list.
		 Use the constants SOURCE_COLS or REFERENCED_COLS to access the lists */
		unsigned getColumnCount(unsigned col_type);

		//! \brief Returns the exclude constraint element count
		unsigned getExcludeElementCount();

		//! \brief Returns a list of exclude elements
		std::vector<ExcludeElement> getExcludeElements();

		/*! \brief Removes one column from internal list using its name.
		 Use the constants SOURCE_COLS or REFERENCED_COLS to access the lists */
		void removeColumn(const QString &name, unsigned col_type);

		//! \brief Remove all columns from the internal lists
		void removeColumns();

		//! \brief Returns the constraint type
		ConstraintType getConstraintType();

		//! \brief Returns the check expression
		QString getExpression();

		//! \brief Returns the referenced table
		BaseTable *getReferencedTable();

		//! \brief Returns the constraint's deferral type
		DeferralType getDeferralType();

		//! \brief Indicates whether the constraint is deferrable
		bool isDeferrable();

		//! \brief Returns if the constraints will propagated to child tables
		bool isNoInherit();

		/*! \brief Returns whether the constraint references columns added
		 by relationship. This method is used as auxiliary
		 to control which constraints reference columns added by the
		 relationship in order to avoid referece breaking due constants
		 connections and disconnections of relationships */
		bool isReferRelationshipAddedColumn();

		/*! \brief Returns the list of all columns that is created by relationships.
	This method is slower than isReferRelationshipAddedColumn() so it's not
	recommended to use it only check if the object is referencing columns
	added by relationship */
		std::vector<Column *> getRelationshipAddedColumns();

		//! \brief Returns the matching type adopted by the constraint
		MatchType getMatchType();

		//! \brief Returns the indexing type adopted by the constraint
		IndexingType getIndexType();

		/*! \brief Returns the SQL / XML definition for the constraint.
		 This method calls getCodeDefintion(unsigned, bool) with the
		 second parameter as false */
		virtual QString getCodeDefinition(unsigned def_type) final;

		/*! \brief Returns the SQL / XML definition for the constraint. The boolean parameter indicates
		 whether the columns added by relationship must appear on the code definition */
		virtual QString getCodeDefinition(unsigned def_type, bool inc_addedbyrel) final;

		virtual QString getDropDefinition(bool cascade) final;

		//! \brief Indicates whether the column exists on the specified internal column list
		bool isColumnExists(Column *column, unsigned col_type);

		/*! \brief Indicates whether the column is referenced in internal column list or exclude element list.
		The second parameter is useful to permit or not the search of column only on referenced columns list. */
		bool isColumnReferenced(Column *column, bool search_only_ref_cols = false);

		/*! \brief Indicates whether the columns are referenced in internal column list
		 * The parameter strict_check will cause the method to return true if and only if all the columns
		 * provided in the list are in the constraint and the provided columns list has the same size as
		 * the one in the constraint */
		bool isColumnsExist(std::vector<Column *> columns, unsigned col_type, bool strict_check);

		//! \brief Adds an exclude element to the constraint using an column (only exclude constraint)
		void addExcludeElement(Column *column, Operator *oper, OperatorClass *op_class, bool use_sorting, bool asc_order, bool nulls_first);

		//! \brief Adds an exclude element to the constraint using an expression (only exclude constraint)
		void addExcludeElement(const QString &expr, Operator *oper, OperatorClass *op_class, bool use_sorting, bool asc_order, bool nulls_first);

		//! \brief Adds an exclude element to the constraint using other pre-configured element (only exclude constraint)
		void addExcludeElement(ExcludeElement elem);

		//! \brief Returns one exclude element using its index
		ExcludeElement getExcludeElement(unsigned elem_idx);

		//! \brief Returns the exclude element index
		int getExcludeElementIndex(ExcludeElement elem);

		//! \brief Remove an exclude element using its index
		void removeExcludeElement(unsigned idx_elem);

		//! \brief Remove all exclude elements from the constraint
		void removeExcludeElements();

		//! \brief Toggles the not-null flag from source columns on primary key constraints. This methods has no effect in other constraint types
		void setColumnsNotNull(bool value);

		virtual QString getSignature(bool format) final;

		/*! \brief Compares two constratins XML definition and returns if they differs. This methods varies a little from
		BaseObject::isCodeDiffersFrom() because here we need to generate xml code including relationship added columns */
		virtual bool isCodeDiffersFrom(BaseObject *object, const QStringList &ignored_attribs={}, const QStringList &ignored_tags={});
};

#endif
