# Template code for data dictionary generation
# CAUTION: Do not modify this file unless you know what you are doing.
# Code generation can be broken if incorrect changes are made.

%if {split} %then
	[<html>
	<head>
	<meta charset="utf-8">
	<title>Data dictionary generated by pgModeler</title>
	<link rel="stylesheet" type="text/css" href="styles.css">
	</head>
	<body>]
%end

$br [<h2>Data dictionary index</h2>]

$br [ ] <ul $sp id="index">
$br [ ] <li><strong>[Database: ]</strong> {name}</strong>

%if {table} %then
	$br [ ] <li><br/><strong>Tables</strong>
	$br [ ] <ul>
	{table}
	$br [ ] </ul>
	$br [ ] </li>
%end

%if {foreigntable} %then
	$br [ ] <li><br/><strong>[Foreign tables]</strong>
	$br [ ] <ul>
	{foreigntable}
	$br [ ] </ul>
	$br [ ] </li>
%end

%if {view} %then
	$br [ ] <li><br/><strong>Views</strong>
	$br [ ] <ul>
	{view}
	$br [ ] </ul>
	$br [ ] </li>
%end

$br [ ] </ul>
$br

%if {split} %then

	[<footer>
	Generated by <a href="https://pgmodeler.io"> PostgreSQL Database Modeler - pgModeler</a><br/>
	Copyright © 2006 - ] {year} [ Raphael Araújo e Silva
	</footer> ]

	</body> $br
	</html>
%end
