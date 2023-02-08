#ifndef GRAPHVIZ_HPP
#define GRAPHVIZ_HPP

#include <cstdio>
#include <string>

#include "location.hpp"
#include "demo_int.hpp"

void Graphviz_SetFile(const char* name);

int Graphviz_Init();
int Graphviz_Quit();

void Graphviz_StartFunction(Location_t location);
void Graphviz_EndFunction();

void Graphviz_CreateNode(const DemoInt* num, const char* color = "black");

void Graphviz_CreateUnorientedEdge(const DemoInt& num, const char* operation, const char* color);
int  Graphviz_CreateOperationNode (const DemoInt& first, const DemoInt& second, const DemoInt& result, const char* operation);

void Graphviz_CreateOrientedEdge(const DemoInt& from, const DemoInt& to, const char* color,
	                             const char* label = "", const char* label_color = "");

void Graphviz_CreateOrientedEdge(const DemoInt& from, const char* to, 
	                             const char* color, const char* label = "", const char* label_color = "");

void Graphviz_CreateOrientedEdge(const char* from, const DemoInt& to, const char* color, 
	                             const char* label = "", const char* label_color = "");

#endif // GRAPHVIZ_HPP