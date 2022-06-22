# Catalog queries for constraints
# CAUTION: Do not modify this file unless you know what you are doing.
# Code generation can be broken if incorrect changes are made.

%if {list} %then
	%set {parent-name} [ ns.nspname || '.' || tb.relname ]

	%if {use-signature} %then
		%set {signature} {parent-name} [ || '.' || ]
	%end

	[ SELECT cs.oid, cs.conname AS name, ] {parent-name} [ AS parent,
	'table' AS parent_type
	FROM pg_constraint AS cs
	LEFT JOIN pg_class AS tb ON cs.conrelid = tb.oid
	LEFT JOIN pg_namespace AS ns ON ns.oid = cs.connamespace ]

	%if {schema} %then
		[ WHERE nspname= ] '{schema}'

		%if {table} %then
			[ AND relkind IN ('r','p','f') AND relname=] '{table}'
		%end
	%end

	%if {last-sys-oid} %then
		%if {schema} %then
			[ AND ]
		%else
			[ WHERE ]
		%end

		[ cs.oid ] {oid-filter-op} $sp {last-sys-oid}
	%end

	%if {last-sys-oid} %or {schema} %then
		[ AND ]
	%else
		[ WHERE ]
	%end

	#Avoiding the listing of constraint generated by constraint triggers and those inherited
	[ cs.oid NOT IN (SELECT DISTINCT tgconstraint FROM pg_trigger WHERE tgconstrindid=0)
	AND cs.conislocal IS TRUE ]

	%if {not-ext-object} %then
		[ AND ]( {not-ext-object} )
	%end

	%if {name-filter} %then
		[ AND ] ( {signature} cs.conname ~* E'{name-filter}' )
	%end

	%if {extra-condition} %then
		[ AND ] ( {extra-condition} )
	%end
%else
	%if {attribs} %then
		[SELECT cs.oid, cs.conname AS name, cs.conrelid AS table,
		cs.conkey AS src_columns, cs.confkey AS dst_columns,
		cs.condeferrable AS deferrable_bool, cs.confrelid AS ref_table,
		cl.reltablespace AS tablespace, cs.conexclop AS operators,
		am.amname AS index_type, cl.reloptions AS factor, ]

		[ id.indkey::oid] $ob $cb [ AS columns,
		  id.indclass::oid] $ob $cb [ AS opclasses,
		  id.indoption::int2] $ob $cb [ AS options, 
		pg_get_expr(id.indpred, id.indrelid) AS condition,
		pg_get_constraintdef(cs.oid) AS expressions, ]

		%if ({pgsql-ver} <=f "9.1") %then
			[ FALSE AS no_inherit_bool, ]
		%else
			[ cs.connoinherit AS no_inherit_bool, ]
		%end


		[ CASE cs.coninhcount
		WHEN 0 THEN FALSE
		ELSE TRUE
		END AS inherited_bool,

		CASE cs.contype
		WHEN 'p' THEN 'pk-constr'
		WHEN 'u' THEN 'uq-constr'
		WHEN 'c' THEN 'ck-constr'
		WHEN 'f' THEN 'fk-constr'
		ELSE 'ex-constr'
		END AS type,

		CASE cs.condeferred
		WHEN TRUE THEN 'INITIALLY DEFERRED'
		ELSE 'INITIALLY IMMEDIATE'
		END AS defer_type,

		CASE cs.confupdtype
		WHEN 'a' THEN 'NO ACTION'
		WHEN 'r' THEN 'RESTRICT'
		WHEN 'c' THEN 'CASCADE'
		WHEN 'n' THEN 'SET NULL'
		WHEN 'd' THEN 'SET DEFAULT'
		ELSE NULL
		END AS upd_action,

		CASE cs.confdeltype
		WHEN 'a' THEN 'NO ACTION'
		WHEN 'r' THEN 'RESTRICT'
		WHEN 'c' THEN 'CASCADE'
		WHEN 'n' THEN 'SET NULL'
		WHEN 'd' THEN 'SET DEFAULT'
		ELSE NULL
		END AS del_action,

		CASE cs.confmatchtype
		WHEN 'f' THEN 'MATCH FULL'
		WHEN 'p' THEN 'MATCH PARTIAL' ]

		[ WHEN ] %if ({pgsql-ver} >=f "9.3") %then 's' %else 'u' %end [ THEN 'MATCH SIMPLE' ]

		[ ELSE NULL
		END AS comparison_type, ]

		[ CASE
		WHEN tb.relkind = 'r' THEN 'table'
		WHEN tb.relkind = 'p' THEN 'table'
		WHEN tb.relkind = 'f' THEN 'foreigntable'
		END AS table_type, ]

		({comment}) [ AS comment ]

		[ FROM pg_constraint AS cs
		LEFT JOIN pg_class AS cl ON cl.oid = cs.conindid
		LEFT JOIN pg_am AS am ON cl.relam = am.oid
		LEFT JOIN pg_index AS id ON id.indexrelid= cs.conindid
		LEFT JOIN pg_class AS tb ON cs.conrelid = tb.oid ]

		%if {schema} %then
			[ LEFT JOIN pg_namespace AS ns ON ns.oid = cs.connamespace
			WHERE ns.nspname= ] '{schema}'

			%if {table} %then
				[ AND tb.relkind IN ('r','p','f') AND tb.relname= ] '{table}'
			%end
		%end

		%if {last-sys-oid} %then
			%if {schema} %then
				[ AND ]
			%else
				[ WHERE ]
			%end

			[ cs.oid ] {oid-filter-op} $sp {last-sys-oid}
		%end

		%if {filter-oids} %then
			%if {schema} %or {last-sys-oid} %then
				[ AND ]
			%else
				[ WHERE ]
			%end

			[ cs.oid IN (] {filter-oids} )
		%end

		%if {filter-oids} %or {last-sys-oid} %or {schema} %then
			[ AND ]
		%else
			[ WHERE ]
		%end

		#Avoiding the listing of constraint generated by constraint triggers and those inherited
		[ cs.oid NOT IN (SELECT DISTINCT tgconstraint FROM pg_trigger WHERE tgconstrindid=0)
		AND cs.conislocal IS TRUE ]

		%if {not-ext-object} %then
			[ AND ]( {not-ext-object} )
		%end
	%end
%end
