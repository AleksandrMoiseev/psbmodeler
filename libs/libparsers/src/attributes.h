/*
# PostgreSQL Database Modeler (pgModeler)
#
# Copyright 2006-2022 - Raphael Araújo e Silva <raphael@pgmodeler.io>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation version 3.
#
# This program is distributed in the hope that it will be useful),
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# The complete text of GPLv3 is at LICENSE file on source code root directory.
# Also), you can get the complete GNU General Public License at <http://www.gnu.org/licenses/>
*/

/**
\ingroup libparsers
\namespace Attributes
\brief Definition of parsers attributes namespace which stores a series of static strings constants used
 to reference the attributes of objects in SQL/XML generation methods.
 Each string stores the name of the attribute used in the schema file "sch" of the respective objects.
\note <strong>Creation date:</strong> 23/09/2008
*/

#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

/* Including QByteArray due to 'QByteArray has no toStdString()'
   error on Qt 5.4 (Windows only) */
#include <QByteArray>
#include <QString>

namespace Attributes {
	extern const QString
	Action,
	ActiveLayers,
	AdminOption,
	AdminRoles,
	Alias,
	Alignment,
	AlignObjsToGrid,
	AllVersions,
	AllowConns,
	AlterCmds,
	AnalyzeFunc,
	AncestorTable,
	AppendAtEod,
	AppendedSql,
	Application,
	ApplyOnServer,
	ArgCount,
	ArgDefaults,
	ArgDefCount,
	ArgModes,
	ArgNames,
	ArgTypes,
	Arguments,
	AscOrder,
	Assignment,
	AttribsPage,
	AttribsPerPage,
	Attribute,
	AutoBrowseDb,
	AutoSaveInterval,
	BackgroundColor,
	BaseType,
	Before,
	BehaviorType,
	Big,
	Bold,
	BorderColor,
	Bottom,
	Buffering,
	BypassRls,
	ByValue,
	Cache,
	CanonicalFunc,
	CanvasColor,
	CanvasCornerMove,
	CaptureNearby,
	Cascade,
	CaseSensitive,
	CastType,
	Category,
	Change,
	Changelog,
	CheckExp,
	CheckUpdate,
	CheckVersions,
	CkConstr,
	ClientEncoding,
	Code,
	CodeCompletion,
	ColIndexes,
	ColIsIdentity,
	CollapseMode,
	Collatable,
	Collation,
	Collations,
	Color,
	Colors,
	ColsComment,
	Column,
	ColumnAlias,
	Columns,
	Command,
	Commands,
	Comment,
	CommutatorOp,
	CompactView,
	CompareToDatabase,
	ComparisonType,
	CompletionTrigger,
	CompositeType,
	Concurrent,
	Condition,
	ConfigFile,
	ConfigParam,
	ConfigParams,
	Configuration,
	ConfirmValidation,
	ConnectCenterPnts,
	ConnectFkToPk,
	Connection,
	Connections,
	ConnectionTimeout,
	ConnectPriv,
	ConnectTableEdges,
	ConnLimit,
	Constraint,
	Constraints,
	ConstrDefs,
	ConstrIndexes,
	ConstrSqlDisabled,
	Contents,
	CopyMode,
	CopyOptions,
	CopyTable,
	Create,
	CreateCmds,
	Created,
	CreateDb,
	CreatePriv,
	CreateRole,
	CrowsFoot,
	CteExpression,
	CurIdentityType,
	CurrentModel,
	CurrentModel,
	CurVersion,
	CustomColor,
	CustomFilter,
	CustomIdxs,
	CustomScale,
	Cycle,
	Dark,
	Database,
	DataDirectory,
	Date,
	DbModel,
	DdlEndToken,
	DeadRowsAmount,
	Declaration,
	DeclInTable,
	Default,
	DefaultCollation,
	DefaultForOps,
	DefaultOwner,
	DefaultSchema,
	DefaultTablespace,
	DefaultValue,
	Deferrable,
	DeferType,
	Definition,
	DelAction,
	Deleted,
	DeletePriv,
	DelEvent,
	Delimiter,
	DelimitersColor,
	Design,
	DestType,
	Deterministic,
	Diff,
	Dimension,
	Directory,
	DisableSmoothness,
	DisplayLineNumbers,
	DockWidgets,
	DomConstraint,
	DontDropMissingObjs,
	Drop,
	DropCmds,
	DropMissingColsConstrs,
	DropTruncCascade,
	DstColPattern,
	DstColumns,
	DstEncoding,
	DstFkPattern,
	DstLabel,
	DstRequired,
	DstTable,
	DstType,
	DynamicLibraryPath,
	DynamicSharedMemory,
	Element,
	Elements,
	ElementsCount,
	EmptyPassword,
	Encoding,
	Encrypted,
	EndExp,
	EnumType,
	Entry,
	EscapeComment,
	Event,
	Events,
	EventType,
	ExactMatch,
	ExcBuiltinArrays,
	ExcludeElement,
	ExConstr,
	ExecType,
	ExecutionCost,
	ExecutPriv,
	ExistingValue,
	Explicit,
	Export,
	ExportToFile,
	Expression,
	Expressions,
	ExtAttribsPage,
	ExtAttribsPerPage,
	ExtObjOids,
	ExtraCondition,
	Factor,
	FadedOut,
	FadeInObjects,
	False,
	Family,
	FastUpdate,
	Fdw,
	File,
	FileAssociated,
	FillColor,
	Filter,
	FilterOids,
	FilterTableTypes,
	FinalFunc,
	FiringType,
	FkColumn,
	FkConstr,
	FkDefs,
	Font,
	FontSize,
	ForceObjsRecreation,
	ForegroundColor,
	ForeignKeys,
	ForeignTableTogglerButtons,
	ForeignTableTogglerBody,
	ForeignTableBody,
	ForeignTableExtBody,
	ForeignTableName,
	ForeignTableSchemaName,
	ForeignTableTitle,
	FormatName,
	FromExp,
	FromSqlFunc,
	Function,
	FunctionType,
	GenAlterCmds,
	General,
	Generated,
	Global,
	GrantOp,
	GridSize,
	GridColor,
	Group,
	HandlerFunc,
	HandlesType,
	HasChanges,
	Hashes,
	HbaFile,
	Height,
	HideExtAttribs,
	HideRelName,
	HideSchNameUserTypes,
	HideTableTags,
	HighlightLines,
	HighlightOrder,
	HistoryMaxLength,
	Icon,
	IconsSize,
	Id,
	IdentFile,
	Identifier,
	IdentityType,
	IgnoredChars,
	IgnoreDuplicErrors,
	IgnoreErrorCodes,
	IgnoreImportErrors,
	Implicit,
	Import,
	ImportExtObjs,
	ImportSysObjs,
	Increment,
	IncludedCols,
	Index,
	IndexElement,
	Indexes,
	IndexType,
	Info,
	InhColumn,
	InhColumns,
	Inherit,
	Inherited,
	InitialCond,
	InitialData,
	InitialExp,
	InlineFunc,
	InputDatabase,
	InputDatabase,
	InputFunc,
	InsertPriv,
	InsEvent,
	InternalLength,
	IntervalType,
	InvertRangeSelTrigger,
	IoCast,
	IsPartitioned,
	IsTemplate,
	Italic,
	Item,
	Items,
	JoinFunc,
	KeepClusterObjs,
	KeepObjsPerms,
	Label,
	Labels,
	LabelsPos,
	Landscape,
	Language,
	LastAnalyze,
	LastAutovacuum,
	LastPosition,
	LastSysOid,
	LastVacuum,
	LastValue,
	LastZoom,
	Layer,
	LayerNameColors,
	LayerRectColors,
	Layers,
	LcCollate,
	LcCollateMod,
	LcCtype,
	LcCtypeMod,
	LeakProof,
	Left,
	LeftType,
	Length,
	Library,
	Light,
	LikeType,
	Line,
	LineHighlightColor,
	LineNumbersBgColor,
	LineNumbersColor,
	Link,
	LinkMode,
	ListenAddresses,
	Locale,
	LocaleMod,
	LockerArc,
	LockerBody,
	Login,
	LookaheadChar,
	LowVerbosity,
	Materialized,
	MaxConnections,
	Maximized,
	MaxObjCount,
	MaxValue,
	Medium,
	Member,
	MemberRoles,
	Merges,
	Metadata,
	MinObjectOpacity,
	MinValue,
	Mode,
	ModelAuthor,
	Name,
	NameFilter,
	NameLabel,
	NamePatterns,
	Names,
	NegatorOp,
	NewIdentityType,
	NewName,
	NewTableName,
	NewVersion,
	Next,
	NnColumn,
	NoInherit,
	None,
	NotExtObject,
	NotNull,
	NullsFirst,
	Object,
	ObjectFinder,
	ObjectId,
	Objects,
	ObjectType,
	ObjCount,
	ObjSelection,
	ObjShadow,
	Oid,
	OidFilterOp,
	Oids,
	OldName,
	OldTableName,
	OldVersion,
	OpClass,
	OpClasses,
	Operator,
	OperatorFunc,
	Operators,
	OpFamily,
	OpListSize,
	Options,
	OriginalPk,
	OutputFunc,
	Owner,
	OwnerColumn,
	Pagination,
	PaperCustomSize,
	PaperMargin,
	PaperOrientation,
	PaperType,
	ParallelType,
	Parameter,
	Parameters,
	ParamIn,
	ParamOut,
	ParamVariadic,
	Parent,
	ParentType,
	Parents,
	Parsable,
	PartialMatch,
	PartitionBoundExpr,
	PartitionedTable,
	PartitionTables,
	Partitioning,
	PartitionKey,
	PartKeyColls,
	PartKeyCols,
	PartKeyExprs,
	PartKeyOpCls,
	Password,
	PasswordEncryption,
	Path,
	Patterns,
	Permission,
	Permissive,
	PerRow,
	PgModelerVersion,
	PgSqlBaseType,
	PgSqlVersion,
	PkColPattern,
	PkColumn,
	PkConstr,
	PkPattern,
	Placeholder,
	Placeholders,
	Points,
	Port,
	Portrait,
	Position,
	PositionInfo,
	Precision,
	Predicate,
	Preferred,
	PrependAtBod,
	PrependedSql,
	PreserveDbName,
	PrependSchema,
	Preset,
	Previous,
	PrintGrid,
	PrintPgNum,
	Privileges,
	PrivilegesGop,
	ProtColumn,
	Protected,
	Provider,
	RangeAttribs,
	RangeType,
	Recent,
	RecentModels,
	RecreateUnmodObjs,
	RectVisible,
	Recursive,
	RecvFunc,
	ReducedForm,
	RefAlias,
	RefColumn,
	RefColumns,
	Refer,
	Reference,
	ReferenceFk,
	References,
	ReferencesPriv,
	Referrers,
	RefName,
	RefTable,
	RefTables,
	RefTableTag,
	RefType,
	RegularExp,
	RelatedForeignKey,
	Relationship,
	Relationship11,
	Relationship1n,
	RelationshipDep,
	RelationshipFk,
	RelationshipGen,
	RelationshipNn,
	RelationshipPart,
	RelationshipTabView,
	Rename,
	Replication,
	RestartSeq,
	RestrictionFunc,
	ReturnsSetOf,
	ReturnTable,
	ReturnType,
	ReuseSequences,
	Revoke,
	Right,
	RightType,
	RlsEnabled,
	RlsForced,
	Role,
	Roles,
	RoleMembers,
	RoleType,
	RowAmount,
	Rules,
	SaveLastPosition,
	SaveRestoreGeometry,
	Schema,
	SchemaOid,
	SearchPath,
	SecurityType,
	SelectExp,
	SelectObjects,
	SelectPriv,
	SendFunc,
	Sequence,
	Server,
	ServerEncoding,
	ServerPid,
	ServerProtocol,
	ServerVersion,
	SessionOpts,
	SetPerms,
	SharedObj,
	ShellTypes,
	ShowAttributesGrid,
	ShowCanvasGrid,
	ShowLayerNames,
	ShowLayerRects,
	ShowMainMenu,
	ShowPageDelimiters,
	ShowSourcePane,
	Signature,
	SimpleExp,
	SimplifiedObjCreation,
	SinglePkColumn,
	Size,
	Small,
	Snippet,
	SortOp,
	SourceEditorApp,
	SourceEditorArgs,
	SourceType,
	SpatialType,
	SpecialPkCols,
	Split,
	SqlDisabled,
	SqlObject,
	SqlTool,
	SqlValidation,
	SrcColPattern,
	SrcColumns,
	SrcEncoding,
	SrcFkPattern,
	SrcLabel,
	SrcRequired,
	SrcTable,
	SrcType,
	Srid,
	Ssl,
	SslCaFile,
	SslCertFile,
	SslCrlFile,
	SslKeyFile,
	StableBeta,
	StableOnly,
	Start,
	StateType,
	Storage,
	StorageParams,
	StoreInFile,
	StrategyNum,
	Stikeout,
	Style,
	Styles,
	Subtype,
	SubtypeDiffFunc,
	Superuser,
	Symbol,
	SyntaxHlTheme,
	System,
	Table,
	TableTogglerButtons,
	TableTogglerBody,
	TableBody,
	TableExtBody,
	TableName,
	TableObject,
	TableSchemaName,
	Tablespace,
	TableTitle,
	TableType,
	Tag,
	TabWidth,
	TemplateDb,
	TemporaryPriv,
	Top,
	ToSqlFunc,
	TpmodInFunc,
	TpmodOutFunc,
	TransformTypes,
	TransitionFunc,
	TriggerFunc,
	TriggerPriv,
	Triggers,
	True,
	Truncate,
	TruncatePriv,
	TruncEvent,
	Trusted,
	TuplesDel,
	TuplesIns,
	Type,
	TypeAttribute,
	TypeClass,
	TypeOid,
	Types,
	TyplesUpd,
	UiLanguage,
	UiTheme,
	Undefined,
	Underline,
	Unique,
	Unlogged,
	Unset,
	UnsetPerms,
	UpdAction,
	Updated,
	UpdatePriv,
	UpdEvent,
	UqColumn,
	UqConstr,
	UqPattern,
	UsagePriv,
	UseChangelog,
	UseCurvedLines,
	UsePlaceholders,
	UseSignature,
	UseSorting,
	UseUniqueNames,
	UsingExp,
	Validation,
	Validator,
	ValidatorFunc,
	Validity,
	Value,
	Values,
	Variable,
	Variation,
	Version,
	ViewTogglerButtons,
	ViewTogglerBody,
	ViewBody,
	ViewExtBody,
	ViewName,
	ViewSchemaName,
	ViewTitle,
	Visible,
	Widget,
	WidgetsGeometry,
	Width,
	Wildcard,
	WindowFunc,
	WithNoData,
	WithoutOids,
	WithTimezone,
	WordDelimiters,
	WordSeparators,
	WorkingDir,
	XPos,
	YPos,
	Year,
	ZValue;
}

#endif
