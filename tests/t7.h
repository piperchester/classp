/* BEGIN HEADER */
#ifndef t7_INCLUDE_
#define t7_INCLUDE_

#include <assert.h>
#include <unordered_map>
#include <utility>

#include "classp.h"

// Include files generated by bison
#include "t7.yacc.hh"
#include "location.hh"
#include "position.hh"

namespace t7 {
using std::istream;
using std::ostream;
using classp::classpPrint;
using classp::classpFormat;
using classp::AttributeMap;

// Location and state information from the parser.
typedef location ParseState;

class AstNode;
/* BEGIN FORWARD DECLARATIONS */
class A;
class B;
class C;
/* END FORWARD DECLARATIONS */

// Base class for t7 AST nodes
class AstNode : public classp::ClasspNode {
 public:
  string className() override { return "AstNode"; }
  AstNode(ParseState parseState)
    : parseState(parseState) {
    }

  // Write out a bracketed form of this AST from the declared syntax.
  virtual void bracketFormat(std::ostream& out, AstNode* self) {
    assert(false);
  }

  ParseState parseState;
};

/* BEGIN CLASS DEFINITIONS */
class A: public AstNode {
 public:
  string className() override { return "A"; }
  A(ParseState parseState, AttributeMap& keyword_args);
  void printMembers(ostream& out) override;
  void format(ostream& out, int precedence) override;

  int x;
  int y;
  bool has_x = false;
  bool has_y = false;
};

class B: public AstNode {
 public:
  string className() override { return "B"; }
  B(ParseState parseState, AttributeMap& keyword_args);
  void printMembers(ostream& out) override;
  void format(ostream& out, int precedence) override;

  vector<int> a1;
  int x;
  bool has_x = false;
};

class C: public AstNode {
 public:
  string className() override { return "C"; }
  C(ParseState parseState, vector<A*> a3, AttributeMap& keyword_args);
  void printMembers(ostream& out) override;
  void format(ostream& out, int precedence) override;

  vector<A*> a1;
  vector<A*> a2;
  vector<A*> a3;
  int x;
  int y;
  int z;
  bool has_x = false;
  bool has_y = false;
  bool has_z = false;
};
/* END CLASS DEFINITIONS */

}  // namespace t7
#endif // t7_INCLUDE_

/* END HEADER */