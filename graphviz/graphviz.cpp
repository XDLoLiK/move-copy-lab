#include "graphviz.hpp"

const char* Graphviz_OUT_FILE_NAME = nullptr;
FILE*       Graphviz_OUT_FILE      = nullptr;
int         Graphviz_COPY_COUNT    = 0;

void Graphviz_SetFile(const char* name)
{
	Graphviz_OUT_FILE_NAME = name;
}

int Graphviz_Init()
{
	static bool is_init = false;
	if (is_init) {
		return 0;
	}

	Graphviz_OUT_FILE = fopen(Graphviz_OUT_FILE_NAME, "w");
	if (!Graphviz_OUT_FILE) {
		return 1;
	}

	fprintf(Graphviz_OUT_FILE, "digraph G {\n"
		                       "node [shape=record];\n"
		                       "fontname=\"Roboto Mono\"\n");
	is_init = true;
	return 0;
}

int Graphviz_Quit()
{
	if (!Graphviz_OUT_FILE) {
		return 1;
	}

	fprintf(Graphviz_OUT_FILE, "subgraph caption1 {\n"
		                       "label=\"...\"\n"
		                       "COPIES [label=\"COPY_COUNT=%d\"]\n"
		                       "TMPS [label=\"TMP_COUNT=%d\"]\n"
		                       "}\n",
		                       Graphviz_GetCopyCount(), DemoInt::tmp_count());

	fprintf(Graphviz_OUT_FILE, "}\n");
	fclose(Graphviz_OUT_FILE);
	Graphviz_OUT_FILE = nullptr;

	std::string cmd_str = "dot " + std::string(Graphviz_OUT_FILE_NAME) + " -Tpng -o " + 
	                               std::string(Graphviz_OUT_FILE_NAME) + ".png";
	system(cmd_str.c_str());
	return 0;
}

int Graphviz_GetCopyCount()
{
	return Graphviz_COPY_COUNT;
}

void Graphviz_IncreaseCopyCount()
{
	Graphviz_COPY_COUNT++;
}

void Graphviz_StartFunction(Location_t location)
{
	static int cluster_count = 0;
	cluster_count++;

	fprintf(Graphviz_OUT_FILE, "subgraph cluster%d {\n"
		                       "color=black\n"
		                       "style=filled\n"
		                       "fillcolor=\"#00000010\"\n"
		                       "label=\"%s:%d %s()\"\n",
		                       cluster_count, location.file, location.line, location.func);
}

void Graphviz_EndFunction()
{
	fprintf(Graphviz_OUT_FILE, "}\n");
}

int Graphviz_CreateUnaryOperationNode(const DemoInt& operand, const DemoInt& result, const char* operation)
{
	static int u_operation_count = 0;
	u_operation_count++;

	fprintf(Graphviz_OUT_FILE, "u_op%d [color=blue, fillcolor=\"#a6eaff\", style=filled,"
		                       "shape=circle, label=\"%s\"]\n",
		                       u_operation_count, operation);

	Graphviz_CreateOrientedEdge(operand,  ("u_op" + std::to_string(u_operation_count)).c_str(), "blue");
	Graphviz_CreateOrientedEdge(("u_op" + std::to_string(u_operation_count)).c_str(), result, "blue");

	return u_operation_count;
}

int Graphviz_CreateOperationNode(const DemoInt& first, const DemoInt& second, const DemoInt& result, 
	                             const char* operation)
{
	static int operation_count = 0;
	operation_count++;

	fprintf(Graphviz_OUT_FILE, "op%d [color=blue, fillcolor=\"#a6eaff\" , style=filled,"
		                       "shape=circle, label=\"%s\"]\n",
		                       operation_count, operation);

	Graphviz_CreateOrientedEdge(first,  ("op" + std::to_string(operation_count)).c_str(), "blue");
	Graphviz_CreateOrientedEdge(second, ("op" + std::to_string(operation_count)).c_str(), "blue");
	Graphviz_CreateOrientedEdge(("op" + std::to_string(operation_count)).c_str(), result, "blue");

	return operation_count;
}

void Graphviz_CreateNode(const DemoInt* num, const char* color, const char* fillcolor)
{
	fprintf(Graphviz_OUT_FILE, "%s [color=%s, fillcolor=\"#%s\", style=filled,"
		                       "label=\"{name=\'%s\'|value=%d|address=%p}\"]\n", 
		                       num->name(), color, fillcolor, num->name(), num->value(), num);
}

void Graphviz_CreateOrientedEdge(const DemoInt& from, const DemoInt& to, const char* color,
	                             const char* label, const char* label_color)
{
	fprintf(Graphviz_OUT_FILE, "%s -> %s [color=%s, label=\"%s\", fontcolor=\"%s\"]\n",
		    from.name(), to.name(), color, label, label_color);
}

void Graphviz_CreateOrientedEdge(const DemoInt& from, const char* to, const char* color,
	                             const char* label, const char* label_color)
{
	fprintf(Graphviz_OUT_FILE, "%s -> %s [color=%s, label=\"%s\", fontcolor=\"%s\"]\n",
		    from.name(), to, color, label, label_color);
}

void Graphviz_CreateOrientedEdge(const char* from, const DemoInt& to, const char* color,
	                             const char* label, const char* label_color)
{
	fprintf(Graphviz_OUT_FILE, "%s -> %s [color=%s, label=\"%s\", fontcolor=\"%s\"]\n",
		    from, to.name(), color, label, label_color);
}
