#pragma once

#include "node.h"
#include "statement.h"


#define BASE_VISITOR(c) virtual bool visit(c* a) { return true; }
#define VISITOR(b, c) virtual bool visit(c* a) { return visit(static_cast<b*>(a)); }

namespace seam::ir::ast
{
	struct visitor
	{
		BASE_VISITOR(node)

		VISITOR(node, statement)
		
		VISITOR(statement, restricted_statement)
		VISITOR(statement, restricted_block)
	};
}

#undef BASE_VISITOR
#undef VISITOR