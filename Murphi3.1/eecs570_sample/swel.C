/******************************
  Program "swel.m" compiled by "Murphi Release 3.1"

  Murphi Last Modefied Date: "Jan 29 1999"
  Murphi Last Compiled date: "Mar 15 2025"
 ******************************/

/********************
  Parameter
 ********************/
#define MURPHI_VERSION "Murphi Release 3.1"
#define MURPHI_DATE "Jan 29 1999"
#define PROTOCOL_NAME "swel"
#define BITS_IN_WORLD 2280
#define ALIGN

/********************
  Include
 ********************/
#include "mu_prolog.inc"

/********************
  Decl declaration
 ********************/

class mu_1_Proc: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Proc& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Proc& val)
    {
      if (val.defined())
        return ( s << mu_1_Proc::values[ int(val) - 1 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_Proc (char *name, int os): mu__byte(1, 3, 2, name, os) {};
  mu_1_Proc (void): mu__byte(1, 3, 2) {};
  mu_1_Proc (int val): mu__byte(1, 3, 2, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -1]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 1] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Proc& a, mu_1_Proc& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
char *mu_1_Proc::values[] =
  { "Proc_1","Proc_2","Proc_3",NULL };

/*** end scalarset declaration ***/
mu_1_Proc mu_1_Proc_undefined_var;

class mu_1_Value: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Value& val){ return value(val.value());};
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Value& val)
    {
      if (val.defined())
        return ( s << mu_1_Value::values[ int(val) - 4 ] );
      else
        return ( s << "Undefined" );
    };

  mu_1_Value (char *name, int os): mu__byte(4, 6, 2, name, os) {};
  mu_1_Value (void): mu__byte(4, 6, 2) {};
  mu_1_Value (int val): mu__byte(4, 6, 2, "Parameter or function result.", 0)
    { operator=(val); };
  char * Name() { return values[ value() -4]; };
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ value() - 4] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
friend int CompareWeight(mu_1_Value& a, mu_1_Value& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
};
char *mu_1_Value::values[] =
  { "Value_1","Value_2","Value_3",NULL };

/*** end scalarset declaration ***/
mu_1_Value mu_1_Value_undefined_var;

class mu_1_L2_cache: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_L2_cache& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_L2_cache& val)
  {
    if (val.defined())
      return ( s << mu_1_L2_cache::values[ int(val) - 7] );
    else return ( s << "Undefined" );
  };

  mu_1_L2_cache (char *name, int os): mu__byte(7, 7, 1, name, os) {};
  mu_1_L2_cache (void): mu__byte(7, 7, 1) {};
  mu_1_L2_cache (int val): mu__byte(7, 7, 1, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -7]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -7] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_L2_cache::values[] = {"L2Type",NULL };

/*** end of enum declaration ***/
mu_1_L2_cache mu_1_L2_cache_undefined_var;

class mu_1_Node: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_Node& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_Node& val)
    {
      if (val.defined())
        return ( s << mu_1_Node::values[ val.indexvalue() ] );
      else
        return ( s << "Undefined" );
    };

  // note thate lb and ub are not used if we have byte compacted state.
  mu_1_Node (char *name, int os): mu__byte(0, 3, 3, name, os) {};
  mu_1_Node (void): mu__byte(0, 3, 3) {};
  mu_1_Node (int val): mu__byte(0, 3, 3, "Parameter or function result.", 0)
    { operator=(val); };
  int indexvalue()
  {
    if ((value() >= 7) && (value() <= 7)) return (value() - 7);
    if ((value() >= 1) && (value() <= 3)) return (value() - 0);
  };
  inline int unionassign(int val)
  {
    if (val >= 0 && val <= 0) return value(val+7);
    if (val >= 1 && val <= 3) return value(val+0);
  };
  char * Name() { return values[ indexvalue() ]; };
friend int CompareWeight(mu_1_Node& a, mu_1_Node& b)
{
  if (!a.defined() && b.defined())
    return -1;
  else if (a.defined() && !b.defined())
    return 1;
  else
    return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void print()
    {
      if (defined()) cout << name << ':' << values[ indexvalue() ] << '\n';
      else cout << name << ":Undefined\n";
    };
  void print_statistic() {};
};
char *mu_1_Node::values[] = {"L2Type","Proc_1","Proc_2","Proc_3",NULL };

/*** end union declaration ***/
mu_1_Node mu_1_Node_undefined_var;

class mu_1_Count: public mu__long
{
 public:
  inline int operator=(int val) { return mu__long::operator=(val); };
  inline int operator=(const mu_1_Count& val) { return mu__long::operator=((int) val); };
  mu_1_Count (char *name, int os): mu__long(-3, 3, 3, name, os) {};
  mu_1_Count (void): mu__long(-3, 3, 3) {};
  mu_1_Count (int val): mu__long(-3, 3, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_Count mu_1_Count_undefined_var;

class mu_1_Sum: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_Sum& val) { return mu__byte::operator=((int) val); };
  mu_1_Sum (char *name, int os): mu__byte(0, 4, 3, name, os) {};
  mu_1_Sum (void): mu__byte(0, 4, 3) {};
  mu_1_Sum (int val): mu__byte(0, 4, 3, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_Sum mu_1_Sum_undefined_var;

class mu_1_VCType: public mu__byte
{
 public:
  inline int operator=(int val) { return mu__byte::operator=(val); };
  inline int operator=(const mu_1_VCType& val) { return mu__byte::operator=((int) val); };
  mu_1_VCType (char *name, int os): mu__byte(0, 2, 2, name, os) {};
  mu_1_VCType (void): mu__byte(0, 2, 2) {};
  mu_1_VCType (int val): mu__byte(0, 2, 2, "Parameter or function result.", 0)
  {
    operator=(val);
  };
  char * Name() { return tsprintf("%d",value()); };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
};

/*** end of subrange decl ***/
mu_1_VCType mu_1_VCType_undefined_var;

class mu_1_MessageType: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1_MessageType& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1_MessageType& val)
  {
    if (val.defined())
      return ( s << mu_1_MessageType::values[ int(val) - 8] );
    else return ( s << "Undefined" );
  };

  mu_1_MessageType (char *name, int os): mu__byte(8, 14, 3, name, os) {};
  mu_1_MessageType (void): mu__byte(8, 14, 3) {};
  mu_1_MessageType (int val): mu__byte(8, 14, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -8]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -8] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1_MessageType::values[] = {"ReadReq","WriteReq","PutS","PutL2","Inv","Ack","Data",NULL };

/*** end of enum declaration ***/
mu_1_MessageType mu_1_MessageType_undefined_var;

class mu_1_Message
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1_MessageType mu_mtype;
  mu_1_Node mu_src;
  mu_1_VCType mu_vc;
  mu_1_Value mu_val;
  mu_1_Count mu_ack;
  mu_0_boolean mu_EL;
  mu_1_Message ( char *n, int os ) { set_self(n,os); };
  mu_1_Message ( void ) {};

  virtual ~mu_1_Message(); 
friend int CompareWeight(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = CompareWeight(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = CompareWeight(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = CompareWeight(a.mu_vc, b.mu_vc);
    if (w!=0) return w;
    w = CompareWeight(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = CompareWeight(a.mu_ack, b.mu_ack);
    if (w!=0) return w;
    w = CompareWeight(a.mu_EL, b.mu_EL);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_Message& a, mu_1_Message& b)
  {
    int w;
    w = Compare(a.mu_mtype, b.mu_mtype);
    if (w!=0) return w;
    w = Compare(a.mu_src, b.mu_src);
    if (w!=0) return w;
    w = Compare(a.mu_vc, b.mu_vc);
    if (w!=0) return w;
    w = Compare(a.mu_val, b.mu_val);
    if (w!=0) return w;
    w = Compare(a.mu_ack, b.mu_ack);
    if (w!=0) return w;
    w = Compare(a.mu_EL, b.mu_EL);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_mtype.MultisetSort();
    mu_src.MultisetSort();
    mu_vc.MultisetSort();
    mu_val.MultisetSort();
    mu_ack.MultisetSort();
    mu_EL.MultisetSort();
  }
  void print_statistic()
  {
    mu_mtype.print_statistic();
    mu_src.print_statistic();
    mu_vc.print_statistic();
    mu_val.print_statistic();
    mu_ack.print_statistic();
    mu_EL.print_statistic();
  }
  void clear() {
    mu_mtype.clear();
    mu_src.clear();
    mu_vc.clear();
    mu_val.clear();
    mu_ack.clear();
    mu_EL.clear();
 };
  void undefine() {
    mu_mtype.undefine();
    mu_src.undefine();
    mu_vc.undefine();
    mu_val.undefine();
    mu_ack.undefine();
    mu_EL.undefine();
 };
  void reset() {
    mu_mtype.reset();
    mu_src.reset();
    mu_vc.reset();
    mu_val.reset();
    mu_ack.reset();
    mu_EL.reset();
 };
  void print() {
    mu_mtype.print();
    mu_src.print();
    mu_vc.print();
    mu_val.print();
    mu_ack.print();
    mu_EL.print();
  };
  void print_diff(state *prevstate) {
    mu_mtype.print_diff(prevstate);
    mu_src.print_diff(prevstate);
    mu_vc.print_diff(prevstate);
    mu_val.print_diff(prevstate);
    mu_ack.print_diff(prevstate);
    mu_EL.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_mtype.to_state(thestate);
    mu_src.to_state(thestate);
    mu_vc.to_state(thestate);
    mu_val.to_state(thestate);
    mu_ack.to_state(thestate);
    mu_EL.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_Message& operator= (const mu_1_Message& from) {
    mu_mtype.value(from.mu_mtype.value());
    mu_src.value(from.mu_src.value());
    mu_vc.value(from.mu_vc.value());
    mu_val.value(from.mu_val.value());
    mu_ack.value(from.mu_ack.value());
    mu_EL.value(from.mu_EL.value());
    return *this;
  };
};

  void mu_1_Message::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_Message::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_Message::set_self(char *n, int os)
{
  name = n;
  mu_mtype.set_self_2(name, ".mtype", os + 0 );
  mu_src.set_self_2(name, ".src", os + 8 );
  mu_vc.set_self_2(name, ".vc", os + 16 );
  mu_val.set_self_2(name, ".val", os + 24 );
  mu_ack.set_self_2(name, ".ack", os + 32 );
  mu_EL.set_self_2(name, ".EL", os + 64 );
}

mu_1_Message::~mu_1_Message()
{
}

/*** end record declaration ***/
mu_1_Message mu_1_Message_undefined_var;

class mu_1__type_0: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_0& val) { return value(val.value()); };
  static char *values[];
  friend ostream& operator<< (ostream& s, mu_1__type_0& val)
  {
    if (val.defined())
      return ( s << mu_1__type_0::values[ int(val) - 15] );
    else return ( s << "Undefined" );
  };

  mu_1__type_0 (char *name, int os): mu__byte(15, 20, 3, name, os) {};
  mu_1__type_0 (void): mu__byte(15, 20, 3) {};
  mu_1__type_0 (int val): mu__byte(15, 20, 3, "Parameter or function result.", 0)
  {
     operator=(val);
  };
  char * Name() { return values[ value() -15]; };
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort() {};
  void print_statistic() {};
  virtual void print()
  {
    if (defined())
      cout << name << ":" << values[ value() -15] << '\n';
    else
      cout << name << ":Undefined\n";
  };
};

char *mu_1__type_0::values[] = {"I","PR","PRW","L2_only","SR","SW",NULL };

/*** end of enum declaration ***/
mu_1__type_0 mu_1__type_0_undefined_var;

class mu_1_L2State
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_1__type_0 mu_state;
  mu_0_boolean mu_shared;
  mu_0_boolean mu_written;
  mu_0_boolean mu_EL;
  mu_1_Value mu_val;
  mu_1_L2State ( char *n, int os ) { set_self(n,os); };
  mu_1_L2State ( void ) {};

  virtual ~mu_1_L2State(); 
friend int CompareWeight(mu_1_L2State& a, mu_1_L2State& b)
  {
    int w;
    w = CompareWeight(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = CompareWeight(a.mu_shared, b.mu_shared);
    if (w!=0) return w;
    w = CompareWeight(a.mu_written, b.mu_written);
    if (w!=0) return w;
    w = CompareWeight(a.mu_EL, b.mu_EL);
    if (w!=0) return w;
    w = CompareWeight(a.mu_val, b.mu_val);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_L2State& a, mu_1_L2State& b)
  {
    int w;
    w = Compare(a.mu_state, b.mu_state);
    if (w!=0) return w;
    w = Compare(a.mu_shared, b.mu_shared);
    if (w!=0) return w;
    w = Compare(a.mu_written, b.mu_written);
    if (w!=0) return w;
    w = Compare(a.mu_EL, b.mu_EL);
    if (w!=0) return w;
    w = Compare(a.mu_val, b.mu_val);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_state.MultisetSort();
    mu_shared.MultisetSort();
    mu_written.MultisetSort();
    mu_EL.MultisetSort();
    mu_val.MultisetSort();
  }
  void print_statistic()
  {
    mu_state.print_statistic();
    mu_shared.print_statistic();
    mu_written.print_statistic();
    mu_EL.print_statistic();
    mu_val.print_statistic();
  }
  void clear() {
    mu_state.clear();
    mu_shared.clear();
    mu_written.clear();
    mu_EL.clear();
    mu_val.clear();
 };
  void undefine() {
    mu_state.undefine();
    mu_shared.undefine();
    mu_written.undefine();
    mu_EL.undefine();
    mu_val.undefine();
 };
  void reset() {
    mu_state.reset();
    mu_shared.reset();
    mu_written.reset();
    mu_EL.reset();
    mu_val.reset();
 };
  void print() {
    mu_state.print();
    mu_shared.print();
    mu_written.print();
    mu_EL.print();
    mu_val.print();
  };
  void print_diff(state *prevstate) {
    mu_state.print_diff(prevstate);
    mu_shared.print_diff(prevstate);
    mu_written.print_diff(prevstate);
    mu_EL.print_diff(prevstate);
    mu_val.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_state.to_state(thestate);
    mu_shared.to_state(thestate);
    mu_written.to_state(thestate);
    mu_EL.to_state(thestate);
    mu_val.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_L2State& operator= (const mu_1_L2State& from) {
    mu_state.value(from.mu_state.value());
    mu_shared.value(from.mu_shared.value());
    mu_written.value(from.mu_written.value());
    mu_EL.value(from.mu_EL.value());
    mu_val.value(from.mu_val.value());
    return *this;
  };
};

  void mu_1_L2State::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_L2State::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_L2State::set_self(char *n, int os)
{
  name = n;
  mu_state.set_self_2(name, ".state", os + 0 );
  mu_shared.set_self_2(name, ".shared", os + 8 );
  mu_written.set_self_2(name, ".written", os + 16 );
  mu_EL.set_self_2(name, ".EL", os + 24 );
  mu_val.set_self_2(name, ".val", os + 32 );
}

mu_1_L2State::~mu_1_L2State()
{
}

/*** end record declaration ***/
mu_1_L2State mu_1_L2State_undefined_var;

class mu_1_L1State
{
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  void set_self(char *n, int os);
  mu_0_boolean mu_EL;
  mu_0_boolean mu_valid;
  mu_1_Value mu_val;
  mu_1_L1State ( char *n, int os ) { set_self(n,os); };
  mu_1_L1State ( void ) {};

  virtual ~mu_1_L1State(); 
friend int CompareWeight(mu_1_L1State& a, mu_1_L1State& b)
  {
    int w;
    w = CompareWeight(a.mu_EL, b.mu_EL);
    if (w!=0) return w;
    w = CompareWeight(a.mu_valid, b.mu_valid);
    if (w!=0) return w;
    w = CompareWeight(a.mu_val, b.mu_val);
    if (w!=0) return w;
  return 0;
}
friend int Compare(mu_1_L1State& a, mu_1_L1State& b)
  {
    int w;
    w = Compare(a.mu_EL, b.mu_EL);
    if (w!=0) return w;
    w = Compare(a.mu_valid, b.mu_valid);
    if (w!=0) return w;
    w = Compare(a.mu_val, b.mu_val);
    if (w!=0) return w;
  return 0;
}
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    mu_EL.MultisetSort();
    mu_valid.MultisetSort();
    mu_val.MultisetSort();
  }
  void print_statistic()
  {
    mu_EL.print_statistic();
    mu_valid.print_statistic();
    mu_val.print_statistic();
  }
  void clear() {
    mu_EL.clear();
    mu_valid.clear();
    mu_val.clear();
 };
  void undefine() {
    mu_EL.undefine();
    mu_valid.undefine();
    mu_val.undefine();
 };
  void reset() {
    mu_EL.reset();
    mu_valid.reset();
    mu_val.reset();
 };
  void print() {
    mu_EL.print();
    mu_valid.print();
    mu_val.print();
  };
  void print_diff(state *prevstate) {
    mu_EL.print_diff(prevstate);
    mu_valid.print_diff(prevstate);
    mu_val.print_diff(prevstate);
  };
  void to_state(state *thestate) {
    mu_EL.to_state(thestate);
    mu_valid.to_state(thestate);
    mu_val.to_state(thestate);
  };
virtual bool isundefined() { Error.Error("Checking undefinedness of a non-base type"); return TRUE;}
virtual bool ismember() { Error.Error("Checking membership for a non-base type"); return TRUE;}
  mu_1_L1State& operator= (const mu_1_L1State& from) {
    mu_EL.value(from.mu_EL.value());
    mu_valid.value(from.mu_valid.value());
    mu_val.value(from.mu_val.value());
    return *this;
  };
};

  void mu_1_L1State::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1_L1State::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1_L1State::set_self(char *n, int os)
{
  name = n;
  mu_EL.set_self_2(name, ".EL", os + 0 );
  mu_valid.set_self_2(name, ".valid", os + 8 );
  mu_val.set_self_2(name, ".val", os + 16 );
}

mu_1_L1State::~mu_1_L1State()
{
}

/*** end record declaration ***/
mu_1_L1State mu_1_L1State_undefined_var;

class mu_1__type_1
{
 public:
  mu_1_L1State array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_1 (char *n, int os) { set_self(n, os); };
  mu_1__type_1 ( void ) {};
  virtual ~mu_1__type_1 ();
  mu_1_L1State& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 1 ) && ( index <= 3 ) )
      return array[ index - 1 ];
    else
      {
        if (index==UNDEFVAL) 
          Error.Error("Indexing to %s using an undefined value.", name);
        else
          Error.Error("Funny index value %d for %s: Proc is internally represented from 3 to 1.\nInternal Error in Type checking.",index, name);
        return array[0];
      }
#else
    return array[ index - 1 ];
#endif
  };
  mu_1__type_1& operator= (const mu_1__type_1& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_1& a, mu_1__type_1& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_1& a, mu_1__type_1& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_1::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_1::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_1::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"Proc_1", i * 24 + os);i++;
array[i].set_self_ar(n,"Proc_2", i * 24 + os);i++;
array[i].set_self_ar(n,"Proc_3", i * 24 + os);i++;
}
mu_1__type_1::~mu_1__type_1()
{
}
/*** end array declaration ***/
mu_1__type_1 mu_1__type_1_undefined_var;

/*** begin multiset declaration ***/
class mu_1__type_2_id: public mu__byte
{
 public:
  inline int operator=(int val) { return value(val); };
  inline int operator=(const mu_1__type_2_id& val) { return value(val.value()); };
  inline operator int() const { return value(); };
  mu_1__type_2_id () : mu__byte(0,3,0) {};
  mu_1__type_2_id (int val) : mu__byte(0,3,0, "Parameter or function result.",0) {operator=(val); };
  char * Name() { return tsprintf("%d", value()); };
};
class mu_1__type_2
{
 public:
  mu_1_Message array[ 4 ];
  int max_size;
  int current_size;
 public:
  mu_0_boolean valid[ 4 ];
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_2 (char *n, int os): current_size(0), max_size(0) { set_self(n, os); };
  mu_1__type_2 ( void ): current_size(0), max_size(0) {};
  virtual ~mu_1__type_2 ();
  mu_1_Message& operator[] (int index) /* const */
  {
    if ((index >= 0) && (index <= 3) && valid[index].value())
      return array[ index ];
    else {
      Error.Error("Internal Error::%d not in index range of %s.", index, name);
      return array[0];
    }
  };
  mu_1__type_2& operator= (const mu_1__type_2& from)
  {
    for (int i = 0; i < 4; i++)
    {
       array[i] = from.array[i];
       valid[i].value(from.valid[i].value());
    };
    current_size = from.get_current_size();
    return *this;
  }

friend int CompareWeight(mu_1__type_2& a, mu_1__type_2& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_2& a, mu_1__type_2& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  void clear() { for (int i = 0; i < 4; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void undefine() { for (int i = 0; i < 4; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void reset() { for (int i = 0; i < 4; i++) { array[i].undefine(); valid[i].value(FALSE); } current_size = 0; };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
     {
       array[i].to_state(thestate);
       valid[i].to_state(thestate);
     }
  };

  int get_current_size() const  {
    int tmp = 0;
    for (int i = 0; i < 4; i++)
      if (valid[i].value()) tmp++;
    return tmp;
  };

   void update_size()
  {
    current_size = 0;
    for (int i = 0; i < 4; i++)
      if (valid[i].value()) current_size++;
    if (max_size<current_size) max_size = current_size;
  };

   inline bool in(const mu_1__type_2_id& id)
  { return valid[(int)id].value(); }
  void print()
  {
    for (int i = 0; i < 4; i++)
      if (valid[i].value())
        array[i].print();
  };

  void print_statistic()
  {
    cout << "	The maximum size for the multiset \"" 
         << name << "\" is: " << max_size << ".\n"; 
  };
  void print_diff(state *prevstate)
  {
    bool prevvalid;
    static state temp;
    StateCopy(&temp, workingstate);
    for (int i = 0; i < 4; i++)
      {
        StateCopy(workingstate, prevstate);
        prevvalid = valid[i].value();
        StateCopy(workingstate, &temp);
        if (prevvalid && !valid[i].value())
          array[i].print();
        if (!prevvalid && valid[i].value())
          array[i].print();
        if (prevvalid && valid[i].value())
          array[i].print_diff(prevstate);
      }
  };
  int multisetadd(const mu_1_Message &element)
  {
    update_size();
    if (current_size >= 4) Error.Error("Maximum size of MultiSet (%s) exceeded.",name);
    int i;
    for (i = 0; i < 4; i++)
      if (!valid[i].value())
        {
          array[i] = element;
          valid[i].value(TRUE);
          break;
        }
    current_size++;
    return i;
  };
  void multisetremove(const mu_1__type_2_id &id)
  {
    update_size();
    if (!valid[(int)id].value()) Error.Error("Internal Error: Illegal Multiset element selected.");
    valid[(int)id].value(FALSE);
    array[(int)id].undefine();
    current_size--;
  };
  void MultisetSort()
  {
    static mu_1_Message temp;

    // compact
    int i,j;
    for (i = 0, j = 0; i < 4; i++)
      if (valid[i].value())
        {
          if (j!=i)
            array[j++] = array[i];
          else
            j++;
        }
    if (j != current_size) current_size = j;
    for (i = j; i < 4; i++)
      array[i].undefine();
    for (i = 0; i < j; i++)
      valid[i].value(TRUE);
    for (i = j; i < 4; i++)
      valid[i].value(FALSE);

    // bubble sort
    for (i = 0; i < current_size; i++)
      for (j = i+1; j < current_size; j++)
        if (Compare(array[i],array[j])>0)
          {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
          }
  }
};

  void mu_1__type_2::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_2::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_2::set_self( char *n, int os)
{
  int i,k;
  name = n;
  for(i = 0; i < 4; i++)
    array[i].set_self(tsprintf("%s{%d}", n,i), i * 72 + os);
  k = os + i * 72;
  for(i = 0; i < 4; i++)
    valid[i].set_self("", i * 8 + k);
};
mu_1__type_2::~mu_1__type_2()
{
}
/*** end multiset declaration ***/
mu_1__type_2 mu_1__type_2_undefined_var;

class mu_1__type_3
{
 public:
  mu_1__type_2 array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_3 (char *n, int os) { set_self(n, os); };
  mu_1__type_3 ( void ) {};
  virtual ~mu_1__type_3 ();
  mu_1__type_2& operator[] (int index) /* const */
  {
    if ( ( index >= 7 ) && ( index <= 7 ) )
      return array[ index - (7) ];
    if ( ( index >= 1 ) && ( index <= 3 ) )
      return array[ index - (0) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_3& operator= (const mu_1__type_3& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_3& a, mu_1__type_3& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_3& a, mu_1__type_3& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_3::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_3::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_3::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"L2Type", i * 320 + os);i++;
array[i].set_self_ar(n,"Proc_1", i * 320 + os);i++;
array[i].set_self_ar(n,"Proc_2", i * 320 + os);i++;
array[i].set_self_ar(n,"Proc_3", i * 320 + os);i++;
}
mu_1__type_3::~mu_1__type_3()
{
}
/*** end array declaration ***/
mu_1__type_3 mu_1__type_3_undefined_var;

class mu_1__type_4
{
 public:
  mu_1_Message array[ 3 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_4 (char *n, int os) { set_self(n, os); };
  mu_1__type_4 ( void ) {};
  virtual ~mu_1__type_4 ();
  mu_1_Message& operator[] (int index) /* const */
  {
#ifndef NO_RUN_TIME_CHECKING
    if ( ( index >= 0 ) && ( index <= 2 ) )
      return array[ index - 0 ];
    else {
      if (index==UNDEFVAL) 
        Error.Error("Indexing to %s using an undefined value.", name);
      else
        Error.Error("%d not in index range of %s.", index, name);
      return array[0];
    }
#else
    return array[ index - 0 ];
#endif
  };
  mu_1__type_4& operator= (const mu_1__type_4& from)
  {
    for (int i = 0; i < 3; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = CompareWeight(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
friend int Compare(mu_1__type_4& a, mu_1__type_4& b)
  {
    int w;
    for (int i=0; i<3; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<3; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<3; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 3; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 3; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 3; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 3; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 3; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 3; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_4::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_4::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_4::set_self( char *n, int os)
{
  char* s;
  name = n;
  for(int i = 0; i < 3; i++) {
    array[i].set_self_ar(n, s=tsprintf("%d",i + 0), i * 72 + os);
    delete[] s;
  }
};
mu_1__type_4::~mu_1__type_4()
{
}
/*** end array declaration ***/
mu_1__type_4 mu_1__type_4_undefined_var;

class mu_1__type_5
{
 public:
  mu_1__type_4 array[ 4 ];
 public:
  char *name;
  char longname[BUFFER_SIZE/4];
  void set_self( char *n, int os);
  void set_self_2( char *n, char *n2, int os);
  void set_self_ar( char *n, char *n2, int os);
  mu_1__type_5 (char *n, int os) { set_self(n, os); };
  mu_1__type_5 ( void ) {};
  virtual ~mu_1__type_5 ();
  mu_1__type_4& operator[] (int index) /* const */
  {
    if ( ( index >= 7 ) && ( index <= 7 ) )
      return array[ index - (7) ];
    if ( ( index >= 1 ) && ( index <= 3 ) )
      return array[ index - (0) ];
    if (index==UNDEFVAL) 
      Error.Error("Indexing to %s using an undefined value.", name);
    else
      Error.Error("Funny index value %d for %s. (Internal Error in Type Checking.",index, name);
    return array[0];
  }
  mu_1__type_5& operator= (const mu_1__type_5& from)
  {
    for (int i = 0; i < 4; i++)
      array[i] = from.array[i];
    return *this;
  }

friend int CompareWeight(mu_1__type_5& a, mu_1__type_5& b)
  {
    return 0;
  }
friend int Compare(mu_1__type_5& a, mu_1__type_5& b)
  {
    int w;
    for (int i=0; i<4; i++) {
      w = Compare(a.array[i], b.array[i]);
      if (w!=0) return w;
    }
    return 0;
  }
  virtual void Permute(PermSet& Perm, int i);
  virtual void SimpleCanonicalize(PermSet& Perm);
  virtual void Canonicalize(PermSet& Perm);
  virtual void SimpleLimit(PermSet& Perm);
  virtual void ArrayLimit(PermSet& Perm);
  virtual void Limit(PermSet& Perm);
  virtual void MultisetLimit(PermSet& Perm);
  virtual void MultisetSort()
  {
    for (int i=0; i<4; i++)
      array[i].MultisetSort();
  }
  void print_statistic()
  {
    for (int i=0; i<4; i++)
      array[i].print_statistic();
  }
  void clear() { for (int i = 0; i < 4; i++) array[i].clear(); };

  void undefine() { for (int i = 0; i < 4; i++) array[i].undefine(); };

  void reset() { for (int i = 0; i < 4; i++) array[i].reset(); };

  void to_state(state *thestate)
  {
    for (int i = 0; i < 4; i++)
      array[i].to_state(thestate);
  };

  void print()
  {
    for (int i = 0; i < 4; i++)
      array[i].print(); };

  void print_diff(state *prevstate)
  {
    for (int i = 0; i < 4; i++)
      array[i].print_diff(prevstate);
  };
};

  void mu_1__type_5::set_self_ar( char *n1, char *n2, int os ) {
    int l1 = strlen(n1), l2 = strlen(n2);
    strcpy( longname, n1 );
    longname[l1] = '[';
    strcpy( longname+l1+1, n2 );
    longname[l1+l2+1] = ']';
    longname[l1+l2+2] = 0;
    set_self( longname, os );
  };
  void mu_1__type_5::set_self_2( char *n1, char *n2, int os ) {
    strcpy( longname, n1 );
    strcat( longname, n2 );
    set_self( longname, os );
  };
void mu_1__type_5::set_self( char *n, int os)
  {
    int i=0;
    name = n;
array[i].set_self_ar(n,"L2Type", i * 216 + os);i++;
array[i].set_self_ar(n,"Proc_1", i * 216 + os);i++;
array[i].set_self_ar(n,"Proc_2", i * 216 + os);i++;
array[i].set_self_ar(n,"Proc_3", i * 216 + os);i++;
}
mu_1__type_5::~mu_1__type_5()
{
}
/*** end array declaration ***/
mu_1__type_5 mu_1__type_5_undefined_var;

const int mu_ProcCount = 3;
const int mu_ValueCount = 3;
const int mu_VC0 = 0;
const int mu_VC1 = 1;
const int mu_VC2 = 2;
const int mu_NumVCs = 3;
const int mu_NetMax = 4;
const int mu_Proc_1 = 1;
const int mu_Proc_2 = 2;
const int mu_Proc_3 = 3;
const int mu_Value_1 = 4;
const int mu_Value_2 = 5;
const int mu_Value_3 = 6;
const int mu_L2Type = 7;
const int mu_ReadReq = 8;
const int mu_WriteReq = 9;
const int mu_PutS = 10;
const int mu_PutL2 = 11;
const int mu_Inv = 12;
const int mu_Ack = 13;
const int mu_Data = 14;
const int mu_I = 15;
const int mu_PR = 16;
const int mu_PRW = 17;
const int mu_L2_only = 18;
const int mu_SR = 19;
const int mu_SW = 20;
/*** Variable declaration ***/
mu_1_L2State mu_L2("L2",0);

/*** Variable declaration ***/
mu_1__type_1 mu_L1("L1",40);

/*** Variable declaration ***/
mu_1__type_3 mu_Net("Net",112);

/*** Variable declaration ***/
mu_1__type_5 mu_InBox("InBox",1392);

/*** Variable declaration ***/
mu_0_boolean mu_msg_processed("msg_processed",2256);

/*** Variable declaration ***/
mu_1_Value mu_LastWrite("LastWrite",2264);

/*** Variable declaration ***/
mu_1_Sum mu_SumV("SumV",2272);

void mu_Send(const mu_1_MessageType& mu_mtype, const mu_1_Node& mu_dst, const mu_1_Node& mu_src, const mu_1_VCType& mu_vc, const mu_1_Value& mu_val, const mu_1_Count& mu_cnt, const mu_0_boolean& mu_EL)
{
/*** Variable declaration ***/
mu_1_Message mu_msg("msg",0);

/*** begin multisetcount 0 declaration ***/
  int mu__intexpr6 = 0;
  {
  mu_1__type_2_id mu_i;
  for (mu_i = 0; ; mu_i=mu_i+1)
    {
      if (mu_Net[mu_dst].valid[(int)mu_i].value())
        {
          if ( mu_true ) mu__intexpr6++;
        }
      if (mu_i == 4-1) break;
    }
  }
/*** end multisetcount 0 declaration ***/
if ( !((mu__intexpr6) < (mu_NetMax)) ) Error.Error("Assertion failed: Too many messages");
if (mu_mtype.isundefined())
  mu_msg.mu_mtype.undefine();
else
  mu_msg.mu_mtype = mu_mtype;
if (mu_src.isundefined())
  mu_msg.mu_src.undefine();
else
  mu_msg.mu_src = mu_src;
if (mu_vc.isundefined())
  mu_msg.mu_vc.undefine();
else
  mu_msg.mu_vc = mu_vc;
if (mu_val.isundefined())
  mu_msg.mu_val.undefine();
else
  mu_msg.mu_val = mu_val;
if (mu_cnt.isundefined())
  mu_msg.mu_ack.undefine();
else
  mu_msg.mu_ack = mu_cnt;
if (mu_EL.isundefined())
  mu_msg.mu_EL.undefine();
else
  mu_msg.mu_EL = mu_EL;
mu_Net[mu_dst].multisetadd(mu_msg);
};
/*** end procedure declaration ***/

void mu_Broadcast(const mu_1_Node& mu_rqst, const mu_1_MessageType& mu_mtype, const mu_1_VCType& mu_vc, const mu_1_Value& mu_val)
{
{
for(int mu_n = 1; mu_n <= 7; mu_n++)
  if (( ( mu_n >= 1 ) && ( mu_n <= 3 ) )|| ( ( mu_n >= 7 ) && ( mu_n <= 7 ) )) {
if ( (mu_n>=1 && mu_n<=3) )
{
bool mu__boolexpr7;
  if (!((mu_n) != (mu_rqst))) mu__boolexpr7 = FALSE ;
  else {
  mu__boolexpr7 = ((mu_n) != (mu_L2Type)) ; 
}
if ( mu__boolexpr7 )
{
mu_L1[mu_n].mu_EL = mu_false;
mu_L1[mu_n].mu_valid = mu_false;
mu_L1[mu_n].mu_val.undefine();
}
}
};
};
};
/*** end procedure declaration ***/

void mu_Broadcast_EL_F(const mu_1_Node& mu_rqst)
{
{
for(int mu_n = 1; mu_n <= 7; mu_n++)
  if (( ( mu_n >= 1 ) && ( mu_n <= 3 ) )|| ( ( mu_n >= 7 ) && ( mu_n <= 7 ) )) {
if ( (mu_n>=1 && mu_n<=3) )
{
bool mu__boolexpr8;
  if (!((mu_n) != (mu_rqst))) mu__boolexpr8 = FALSE ;
  else {
  mu__boolexpr8 = ((mu_n) != (mu_L2Type)) ; 
}
if ( mu__boolexpr8 )
{
mu_L1[mu_n].mu_EL = mu_false;
}
}
};
};
};
/*** end procedure declaration ***/

void mu_GrantL1(const mu_1_Node& mu_n, const mu_1_Value& mu_data)
{
mu_L1[mu_n].mu_EL = mu_true;
mu_L1[mu_n].mu_valid = mu_true;
if (mu_data.isundefined())
  mu_L1[mu_n].mu_val.undefine();
else
  mu_L1[mu_n].mu_val = mu_data;
};
/*** end procedure declaration ***/

void mu_GrantL1_Shared(const mu_1_Node& mu_n, const mu_1_Value& mu_data)
{
mu_L1[mu_n].mu_EL = mu_false;
mu_L1[mu_n].mu_valid = mu_true;
if (mu_data.isundefined())
  mu_L1[mu_n].mu_val.undefine();
else
  mu_L1[mu_n].mu_val = mu_data;
};
/*** end procedure declaration ***/

void mu_PutL1(const mu_1_Proc& mu_n)
{
mu_L1[mu_n].mu_EL = mu_false;
mu_L1[mu_n].mu_valid = mu_false;
mu_L1[mu_n].mu_val.undefine();
};
/*** end procedure declaration ***/

void mu_PutAllL1()
{
{
for(int mu_n = 1; mu_n <= 3; mu_n++) {
mu_PutL1 ( mu_n );
};
};
};
/*** end procedure declaration ***/

void mu_ErrorUnhandledMsg(mu_1_Message& mu_msg, const mu_1_Node& mu_n)
{
Error.Error("Error: Unhandled message type!");
};
/*** end procedure declaration ***/

void mu_ErrorUnhandledState()
{
Error.Error("Error: Unhandled state!");
};
/*** end procedure declaration ***/

void mu_L2Receive(mu_1_Message& mu_msg)
{
switch ((int) mu_L2.mu_state) {
case mu_I:
switch ((int) mu_msg.mu_mtype) {
case mu_WriteReq:
mu_L2.mu_state = mu_PRW;
mu_L2.mu_written = mu_true;
mu_L2.mu_shared = mu_false;
mu_L2.mu_EL = mu_false;
mu_L2.mu_val = mu_msg.mu_val;
mu_GrantL1 ( mu_msg.mu_src, mu_L2.mu_val );
break;
case mu_ReadReq:
mu_L2.mu_state = mu_PR;
mu_L2.mu_written = mu_false;
mu_L2.mu_shared = mu_false;
mu_L2.mu_EL = mu_false;
mu_GrantL1 ( mu_msg.mu_src, mu_L2.mu_val );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_L2Type );
break;
}
break;
case mu_PR:
switch ((int) mu_msg.mu_mtype) {
case mu_WriteReq:
if ( (mu_msg.mu_EL) == (mu_true) )
{
mu_L2.mu_written = mu_true;
mu_L2.mu_state = mu_PRW;
mu_L2.mu_EL = mu_false;
mu_L2.mu_val = mu_msg.mu_val;
}
else
{
mu_Broadcast ( (int)mu_L2Type, mu_Inv, mu_VC2, mu_1_Value_undefined_var );
mu_L2.mu_state = mu_SW;
mu_L2.mu_written = mu_true;
mu_L2.mu_shared = mu_true;
mu_L2.mu_EL = mu_true;
}
break;
case mu_ReadReq:
mu_L2.mu_state = mu_SR;
mu_L2.mu_shared = mu_true;
mu_L2.mu_EL = mu_false;
mu_GrantL1_Shared ( mu_msg.mu_src, mu_L2.mu_val );
mu_Broadcast_EL_F ( mu_msg.mu_src );
break;
case mu_PutS:
mu_L2.mu_state = mu_L2_only;
mu_L2.mu_EL = mu_true;
mu_PutL1 ( (int)mu_msg.mu_src );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_L2Type );
break;
}
break;
case mu_PRW:
switch ((int) mu_msg.mu_mtype) {
case mu_WriteReq:
if ( (mu_msg.mu_EL) == (mu_true) )
{
mu_L2.mu_written = mu_true;
mu_L2.mu_state = mu_PRW;
mu_L2.mu_EL = mu_false;
mu_L2.mu_val = mu_msg.mu_val;
}
else
{
mu_Broadcast ( (int)mu_L2Type, mu_Inv, mu_VC2, mu_1_Value_undefined_var );
mu_L2.mu_state = mu_SW;
mu_L2.mu_written = mu_true;
mu_L2.mu_shared = mu_true;
mu_L2.mu_EL = mu_true;
}
break;
case mu_ReadReq:
mu_L2.mu_state = mu_SW;
mu_L2.mu_written = mu_true;
mu_L2.mu_shared = mu_true;
mu_L2.mu_EL = mu_true;
mu_GrantL1 ( mu_msg.mu_src, mu_L2.mu_val );
mu_Broadcast ( (int)mu_L2Type, mu_Inv, mu_VC2, mu_1_Value_undefined_var );
break;
case mu_PutS:
mu_L2.mu_state = mu_L2_only;
mu_L2.mu_written = mu_true;
mu_L2.mu_EL = mu_true;
mu_PutL1 ( (int)mu_msg.mu_src );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_L2Type );
break;
}
break;
case mu_L2_only:
switch ((int) mu_msg.mu_mtype) {
case mu_WriteReq:
mu_L2.mu_state = mu_PRW;
mu_L2.mu_written = mu_true;
mu_L2.mu_EL = mu_false;
mu_L2.mu_val = mu_msg.mu_val;
mu_GrantL1 ( mu_msg.mu_src, mu_L2.mu_val );
break;
case mu_ReadReq:
mu_L2.mu_state = mu_PR;
mu_L2.mu_EL = mu_false;
mu_GrantL1 ( mu_msg.mu_src, mu_L2.mu_val );
break;
case mu_PutS:
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_L2Type );
break;
}
break;
case mu_SR:
switch ((int) mu_msg.mu_mtype) {
case mu_WriteReq:
mu_Broadcast ( (int)mu_L2Type, mu_Inv, mu_VC2, mu_1_Value_undefined_var );
mu_L2.mu_state = mu_SW;
mu_L2.mu_written = mu_true;
mu_L2.mu_shared = mu_true;
mu_L2.mu_EL = mu_true;
mu_L2.mu_val = mu_msg.mu_val;
break;
case mu_ReadReq:
mu_L2.mu_state = mu_SR;
mu_L2.mu_shared = mu_true;
mu_L2.mu_EL = mu_false;
mu_GrantL1_Shared ( mu_msg.mu_src, mu_L2.mu_val );
break;
case mu_PutL2:
mu_L2.mu_state = mu_I;
mu_L2.mu_written = mu_false;
mu_L2.mu_shared = mu_false;
mu_L2.mu_EL = mu_false;
mu_PutAllL1 (  );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_L2Type );
break;
}
break;
case mu_SW:
switch ((int) mu_msg.mu_mtype) {
case mu_WriteReq:
mu_L2.mu_state = mu_SW;
mu_L2.mu_written = mu_true;
mu_L2.mu_shared = mu_true;
mu_L2.mu_EL = mu_true;
mu_L2.mu_val = mu_msg.mu_val;
break;
case mu_ReadReq:
mu_L2.mu_state = mu_SW;
mu_L2.mu_written = mu_true;
mu_L2.mu_shared = mu_true;
mu_L2.mu_EL = mu_true;
break;
case mu_PutL2:
mu_L2.mu_state = mu_I;
mu_L2.mu_written = mu_false;
mu_L2.mu_shared = mu_false;
mu_L2.mu_EL = mu_false;
mu_PutAllL1 (  );
break;
default:
mu_ErrorUnhandledMsg ( mu_msg, (int)mu_L2Type );
break;
}
break;
default:
mu_ErrorUnhandledState (  );
break;
}
};
/*** end procedure declaration ***/

mu_1_Sum mu_Sumfunc()
{
/*** Variable declaration ***/
mu_1_Sum mu_total("total",0);

mu_total = 0;
{
for(int mu_n = 1; mu_n <= 3; mu_n++) {
if ( mu_L1[mu_n].mu_EL )
{
mu_total = (mu_total) + (1);
}
};
};
if ( mu_L2.mu_EL )
{
mu_total = (mu_total) + (1);
}
return mu_total;
  Error.Error("The end of function Sumfunc reached without returning values.");
};
/*** end function declaration ***/





/********************
  The world
 ********************/
void world_class::clear()
{
  mu_L2.clear();
  mu_L1.clear();
  mu_Net.clear();
  mu_InBox.clear();
  mu_msg_processed.clear();
  mu_LastWrite.clear();
  mu_SumV.clear();
}
void world_class::undefine()
{
  mu_L2.undefine();
  mu_L1.undefine();
  mu_Net.undefine();
  mu_InBox.undefine();
  mu_msg_processed.undefine();
  mu_LastWrite.undefine();
  mu_SumV.undefine();
}
void world_class::reset()
{
  mu_L2.reset();
  mu_L1.reset();
  mu_Net.reset();
  mu_InBox.reset();
  mu_msg_processed.reset();
  mu_LastWrite.reset();
  mu_SumV.reset();
}
void world_class::print()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_L2.print();
  mu_L1.print();
  mu_Net.print();
  mu_InBox.print();
  mu_msg_processed.print();
  mu_LastWrite.print();
  mu_SumV.print();
    num_calls--;
}
}
void world_class::print_statistic()
{
  static int num_calls = 0; /* to ward off recursive calls. */
  if ( num_calls == 0 ) {
    num_calls++;
  mu_L2.print_statistic();
  mu_L1.print_statistic();
  mu_Net.print_statistic();
  mu_InBox.print_statistic();
  mu_msg_processed.print_statistic();
  mu_LastWrite.print_statistic();
  mu_SumV.print_statistic();
    num_calls--;
}
}
void world_class::print_diff( state *prevstate )
{
  if ( prevstate != NULL )
  {
    mu_L2.print_diff(prevstate);
    mu_L1.print_diff(prevstate);
    mu_Net.print_diff(prevstate);
    mu_InBox.print_diff(prevstate);
    mu_msg_processed.print_diff(prevstate);
    mu_LastWrite.print_diff(prevstate);
    mu_SumV.print_diff(prevstate);
  }
  else
print();
}
void world_class::to_state(state *newstate)
{
  mu_L2.to_state( newstate );
  mu_L1.to_state( newstate );
  mu_Net.to_state( newstate );
  mu_InBox.to_state( newstate );
  mu_msg_processed.to_state( newstate );
  mu_LastWrite.to_state( newstate );
  mu_SumV.to_state( newstate );
}
void world_class::setstate(state *thestate)
{
}


/********************
  Rule declarations
 ********************/
/******************** RuleBase0 ********************/
class RuleBase0
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1__type_2_id mu_midx;
    mu_midx.value((r % 4) + 0);
    r = r / 4;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
    return tsprintf("receive-net, midx:%s, n:%s", mu_midx.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1__type_2_id mu_midx;
    mu_midx.value((r % 4) + 0);
    r = r / 4;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
  if (!mu_Net[mu_n].in(mu_midx)) { return FALSE; }
  mu_1__type_2& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
  mu_1__type_4& mu_box = mu_InBox[mu_n];
bool mu__boolexpr9;
bool mu__boolexpr10;
  if ((mu_msg.mu_vc) == (mu_VC2)) mu__boolexpr10 = TRUE ;
  else {
bool mu__boolexpr11;
/*** begin multisetcount 1 declaration ***/
  int mu__intexpr12 = 0;
  {
  mu_1__type_2_id mu_m;
  for (mu_m = 0; ; mu_m=mu_m+1)
    {
      if (mu_chan.valid[(int)mu_m].value())
        {
          if ( (mu_chan[mu_m].mu_vc) == (mu_VC2) ) mu__intexpr12++;
        }
      if (mu_m == 4-1) break;
    }
  }
/*** end multisetcount 1 declaration ***/
  if (!((mu__intexpr12) == (0))) mu__boolexpr11 = FALSE ;
  else {
  mu__boolexpr11 = ((mu_msg.mu_vc) == (mu_VC1)) ; 
}
  mu__boolexpr10 = (mu__boolexpr11) ; 
}
  if (mu__boolexpr10) mu__boolexpr9 = TRUE ;
  else {
bool mu__boolexpr13;
bool mu__boolexpr14;
/*** begin multisetcount 2 declaration ***/
  int mu__intexpr15 = 0;
  {
  mu_1__type_2_id mu_m;
  for (mu_m = 0; ; mu_m=mu_m+1)
    {
      if (mu_chan.valid[(int)mu_m].value())
        {
          if ( (mu_chan[mu_m].mu_vc) == (mu_VC2) ) mu__intexpr15++;
        }
      if (mu_m == 4-1) break;
    }
  }
/*** end multisetcount 2 declaration ***/
  if (!((mu__intexpr15) == (0))) mu__boolexpr14 = FALSE ;
  else {
/*** begin multisetcount 3 declaration ***/
  int mu__intexpr16 = 0;
  {
  mu_1__type_2_id mu_m;
  for (mu_m = 0; ; mu_m=mu_m+1)
    {
      if (mu_chan.valid[(int)mu_m].value())
        {
          if ( (mu_chan[mu_m].mu_vc) == (mu_VC1) ) mu__intexpr16++;
        }
      if (mu_m == 4-1) break;
    }
  }
/*** end multisetcount 3 declaration ***/
  mu__boolexpr14 = ((mu__intexpr16) == (0)) ; 
}
  if (!(mu__boolexpr14)) mu__boolexpr13 = FALSE ;
  else {
  mu__boolexpr13 = ((mu_msg.mu_vc) == (mu_VC0)) ; 
}
  mu__boolexpr9 = (mu__boolexpr13) ; 
}
  return mu__boolexpr9;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 0;
    static mu_1__type_2_id mu_midx;
    mu_midx.value((r % 4) + 0);
    r = r / 4;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
    while (what_rule < 16 && mu_midx.value()<4 )
      {
        if ( ( TRUE && mu_Net[mu_n].in(mu_midx) ) ) {
  mu_1__type_2& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
  mu_1__type_4& mu_box = mu_InBox[mu_n];
bool mu__boolexpr17;
bool mu__boolexpr18;
  if ((mu_msg.mu_vc) == (mu_VC2)) mu__boolexpr18 = TRUE ;
  else {
bool mu__boolexpr19;
/*** begin multisetcount 1 declaration ***/
  int mu__intexpr20 = 0;
  {
  mu_1__type_2_id mu_m;
  for (mu_m = 0; ; mu_m=mu_m+1)
    {
      if (mu_chan.valid[(int)mu_m].value())
        {
          if ( (mu_chan[mu_m].mu_vc) == (mu_VC2) ) mu__intexpr20++;
        }
      if (mu_m == 4-1) break;
    }
  }
/*** end multisetcount 1 declaration ***/
  if (!((mu__intexpr20) == (0))) mu__boolexpr19 = FALSE ;
  else {
  mu__boolexpr19 = ((mu_msg.mu_vc) == (mu_VC1)) ; 
}
  mu__boolexpr18 = (mu__boolexpr19) ; 
}
  if (mu__boolexpr18) mu__boolexpr17 = TRUE ;
  else {
bool mu__boolexpr21;
bool mu__boolexpr22;
/*** begin multisetcount 2 declaration ***/
  int mu__intexpr23 = 0;
  {
  mu_1__type_2_id mu_m;
  for (mu_m = 0; ; mu_m=mu_m+1)
    {
      if (mu_chan.valid[(int)mu_m].value())
        {
          if ( (mu_chan[mu_m].mu_vc) == (mu_VC2) ) mu__intexpr23++;
        }
      if (mu_m == 4-1) break;
    }
  }
/*** end multisetcount 2 declaration ***/
  if (!((mu__intexpr23) == (0))) mu__boolexpr22 = FALSE ;
  else {
/*** begin multisetcount 3 declaration ***/
  int mu__intexpr24 = 0;
  {
  mu_1__type_2_id mu_m;
  for (mu_m = 0; ; mu_m=mu_m+1)
    {
      if (mu_chan.valid[(int)mu_m].value())
        {
          if ( (mu_chan[mu_m].mu_vc) == (mu_VC1) ) mu__intexpr24++;
        }
      if (mu_m == 4-1) break;
    }
  }
/*** end multisetcount 3 declaration ***/
  mu__boolexpr22 = ((mu__intexpr24) == (0)) ; 
}
  if (!(mu__boolexpr22)) mu__boolexpr21 = FALSE ;
  else {
  mu__boolexpr21 = ((mu_msg.mu_vc) == (mu_VC0)) ; 
}
  mu__boolexpr17 = (mu__boolexpr21) ; 
}
              if (mu__boolexpr17) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 1;
        }
        else
          what_rule += 1;
    r = what_rule - 0;
    mu_midx.value((r % 4) + 0);
    r = r / 4;
    mu_n.unionassign(r % 4);
    r = r / 4;
    }
  }

  void Code(unsigned r)
  {
    static mu_1__type_2_id mu_midx;
    mu_midx.value((r % 4) + 0);
    r = r / 4;
    static mu_1_Node mu_n;
    mu_n.unionassign(r % 4);
    r = r / 4;
  mu_1__type_2& mu_chan = mu_Net[mu_n];
  mu_1_Message& mu_msg = mu_chan[mu_midx];
  mu_1__type_4& mu_box = mu_InBox[mu_n];
if ( (mu_n>=7 && mu_n<=7) )
{
mu_L2Receive ( mu_msg );
mu_chan.multisetremove(mu_midx);
}
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase1 ********************/
class RuleBase1
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("SW Evict, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr25;
bool mu__boolexpr26;
  if ((mu_p2.mu_state) == (mu_SW)) mu__boolexpr26 = TRUE ;
  else {
  mu__boolexpr26 = ((mu_p2.mu_state) == (mu_SR)) ; 
}
  if (!(mu__boolexpr26)) mu__boolexpr25 = FALSE ;
  else {
  mu__boolexpr25 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  return mu__boolexpr25;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 16;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 25 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr27;
bool mu__boolexpr28;
  if ((mu_p2.mu_state) == (mu_SW)) mu__boolexpr28 = TRUE ;
  else {
  mu__boolexpr28 = ((mu_p2.mu_state) == (mu_SR)) ; 
}
  if (!(mu__boolexpr28)) mu__boolexpr27 = FALSE ;
  else {
  mu__boolexpr27 = ((mu_p.mu_EL) == (mu_false)) ; 
}
              if (mu__boolexpr27) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 16;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_PutL2, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_1_Value_undefined_var, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase2 ********************/
class RuleBase2
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("SW Write, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr29;
bool mu__boolexpr30;
  if (!((mu_p2.mu_state) == (mu_SW))) mu__boolexpr30 = FALSE ;
  else {
  mu__boolexpr30 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr30)) mu__boolexpr29 = FALSE ;
  else {
  mu__boolexpr29 = ((mu_p2.mu_EL) == (mu_true)) ; 
}
  return mu__boolexpr29;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 25;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 34 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr31;
bool mu__boolexpr32;
  if (!((mu_p2.mu_state) == (mu_SW))) mu__boolexpr32 = FALSE ;
  else {
  mu__boolexpr32 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr32)) mu__boolexpr31 = FALSE ;
  else {
  mu__boolexpr31 = ((mu_p2.mu_EL) == (mu_true)) ; 
}
              if (mu__boolexpr31) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 25;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_WriteReq, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_v, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase3 ********************/
class RuleBase3
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("SW Read, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr33;
bool mu__boolexpr34;
  if (!((mu_p2.mu_state) == (mu_SW))) mu__boolexpr34 = FALSE ;
  else {
  mu__boolexpr34 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr34)) mu__boolexpr33 = FALSE ;
  else {
  mu__boolexpr33 = ((mu_p2.mu_EL) == (mu_true)) ; 
}
  return mu__boolexpr33;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 34;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 43 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr35;
bool mu__boolexpr36;
  if (!((mu_p2.mu_state) == (mu_SW))) mu__boolexpr36 = FALSE ;
  else {
  mu__boolexpr36 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr36)) mu__boolexpr35 = FALSE ;
  else {
  mu__boolexpr35 = ((mu_p2.mu_EL) == (mu_true)) ; 
}
              if (mu__boolexpr35) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 34;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_ReadReq, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_1_Value_undefined_var, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase4 ********************/
class RuleBase4
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("Additional Sharer Read, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr37;
bool mu__boolexpr38;
  if (!((mu_p2.mu_state) == (mu_PR))) mu__boolexpr38 = FALSE ;
  else {
  mu__boolexpr38 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr38)) mu__boolexpr37 = FALSE ;
  else {
  mu__boolexpr37 = ((mu_p2.mu_EL) == (mu_false)) ; 
}
  return mu__boolexpr37;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 43;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 52 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr39;
bool mu__boolexpr40;
  if (!((mu_p2.mu_state) == (mu_PR))) mu__boolexpr40 = FALSE ;
  else {
  mu__boolexpr40 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr40)) mu__boolexpr39 = FALSE ;
  else {
  mu__boolexpr39 = ((mu_p2.mu_EL) == (mu_false)) ; 
}
              if (mu__boolexpr39) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 43;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_ReadReq, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_1_Value_undefined_var, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase5 ********************/
class RuleBase5
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("Any Write, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr41;
bool mu__boolexpr42;
  if (!((mu_p2.mu_state) == (mu_SR))) mu__boolexpr42 = FALSE ;
  else {
  mu__boolexpr42 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr42)) mu__boolexpr41 = FALSE ;
  else {
  mu__boolexpr41 = ((mu_p2.mu_EL) == (mu_false)) ; 
}
  return mu__boolexpr41;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 52;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 61 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr43;
bool mu__boolexpr44;
  if (!((mu_p2.mu_state) == (mu_SR))) mu__boolexpr44 = FALSE ;
  else {
  mu__boolexpr44 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr44)) mu__boolexpr43 = FALSE ;
  else {
  mu__boolexpr43 = ((mu_p2.mu_EL) == (mu_false)) ; 
}
              if (mu__boolexpr43) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 52;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_WriteReq, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_v, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase6 ********************/
class RuleBase6
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("Other L1 Write, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr45;
bool mu__boolexpr46;
  if (!((mu_p2.mu_state) == (mu_PR))) mu__boolexpr46 = FALSE ;
  else {
  mu__boolexpr46 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr46)) mu__boolexpr45 = FALSE ;
  else {
  mu__boolexpr45 = ((mu_p2.mu_EL) == (mu_false)) ; 
}
  return mu__boolexpr45;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 61;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 70 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr47;
bool mu__boolexpr48;
  if (!((mu_p2.mu_state) == (mu_PR))) mu__boolexpr48 = FALSE ;
  else {
  mu__boolexpr48 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr48)) mu__boolexpr47 = FALSE ;
  else {
  mu__boolexpr47 = ((mu_p2.mu_EL) == (mu_false)) ; 
}
              if (mu__boolexpr47) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 61;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_WriteReq, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_v, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase7 ********************/
class RuleBase7
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("Additional Sharer Write, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr49;
bool mu__boolexpr50;
  if (!((mu_p2.mu_state) == (mu_PRW))) mu__boolexpr50 = FALSE ;
  else {
  mu__boolexpr50 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr50)) mu__boolexpr49 = FALSE ;
  else {
  mu__boolexpr49 = ((mu_p2.mu_EL) == (mu_false)) ; 
}
  return mu__boolexpr49;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 70;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 79 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr51;
bool mu__boolexpr52;
  if (!((mu_p2.mu_state) == (mu_PRW))) mu__boolexpr52 = FALSE ;
  else {
  mu__boolexpr52 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr52)) mu__boolexpr51 = FALSE ;
  else {
  mu__boolexpr51 = ((mu_p2.mu_EL) == (mu_false)) ; 
}
              if (mu__boolexpr51) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 70;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_WriteReq, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_v, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase8 ********************/
class RuleBase8
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("Additional Sharer Read, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr53;
bool mu__boolexpr54;
  if (!((mu_p2.mu_state) == (mu_PRW))) mu__boolexpr54 = FALSE ;
  else {
  mu__boolexpr54 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr54)) mu__boolexpr53 = FALSE ;
  else {
  mu__boolexpr53 = ((mu_p2.mu_EL) == (mu_false)) ; 
}
  return mu__boolexpr53;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 79;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 88 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr55;
bool mu__boolexpr56;
  if (!((mu_p2.mu_state) == (mu_PRW))) mu__boolexpr56 = FALSE ;
  else {
  mu__boolexpr56 = ((mu_p.mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr56)) mu__boolexpr55 = FALSE ;
  else {
  mu__boolexpr55 = ((mu_p2.mu_EL) == (mu_false)) ; 
}
              if (mu__boolexpr55) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 79;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_ReadReq, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_1_Value_undefined_var, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase9 ********************/
class RuleBase9
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("Exclusive L1 Write, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr57;
  if (!((mu_p2.mu_state) == (mu_PR))) mu__boolexpr57 = FALSE ;
  else {
  mu__boolexpr57 = ((mu_p.mu_valid) == (mu_true)) ; 
}
  return mu__boolexpr57;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 88;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 97 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr58;
  if (!((mu_p2.mu_state) == (mu_PR))) mu__boolexpr58 = FALSE ;
  else {
  mu__boolexpr58 = ((mu_p.mu_valid) == (mu_true)) ; 
}
              if (mu__boolexpr58) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 88;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_WriteReq, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_v, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase10 ********************/
class RuleBase10
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("L1 Eviction PRW, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr59;
  if (!((mu_p2.mu_state) == (mu_PRW))) mu__boolexpr59 = FALSE ;
  else {
  mu__boolexpr59 = ((mu_p.mu_EL) == (mu_true)) ; 
}
  return mu__boolexpr59;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 97;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 106 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr60;
  if (!((mu_p2.mu_state) == (mu_PRW))) mu__boolexpr60 = FALSE ;
  else {
  mu__boolexpr60 = ((mu_p.mu_EL) == (mu_true)) ; 
}
              if (mu__boolexpr60) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 97;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_PutS, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_1_Value_undefined_var, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase11 ********************/
class RuleBase11
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("First L1 Write, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr61;
  if (!((mu_p2.mu_state) == (mu_L2_only))) mu__boolexpr61 = FALSE ;
  else {
  mu__boolexpr61 = ((mu_p.mu_valid) == (mu_false)) ; 
}
  return mu__boolexpr61;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 106;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 115 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr62;
  if (!((mu_p2.mu_state) == (mu_L2_only))) mu__boolexpr62 = FALSE ;
  else {
  mu__boolexpr62 = ((mu_p.mu_valid) == (mu_false)) ; 
}
              if (mu__boolexpr62) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 106;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_WriteReq, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_v, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase12 ********************/
class RuleBase12
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("L1 Eviction, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr63;
  if (!((mu_p2.mu_state) == (mu_PR))) mu__boolexpr63 = FALSE ;
  else {
  mu__boolexpr63 = ((mu_p.mu_EL) == (mu_true)) ; 
}
  return mu__boolexpr63;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 115;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 124 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr64;
  if (!((mu_p2.mu_state) == (mu_PR))) mu__boolexpr64 = FALSE ;
  else {
  mu__boolexpr64 = ((mu_p.mu_EL) == (mu_true)) ; 
}
              if (mu__boolexpr64) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 115;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_PutS, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_1_Value_undefined_var, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase13 ********************/
class RuleBase13
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    return tsprintf("First L1 Read, v:%s, n:%s", mu_v.Name(), mu_n.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr65;
  if (!((mu_p2.mu_state) == (mu_L2_only))) mu__boolexpr65 = FALSE ;
  else {
  mu__boolexpr65 = ((mu_p.mu_valid) == (mu_false)) ; 
}
  return mu__boolexpr65;
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 124;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    while (what_rule < 133 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
bool mu__boolexpr66;
  if (!((mu_p2.mu_state) == (mu_L2_only))) mu__boolexpr66 = FALSE ;
  else {
  mu__boolexpr66 = ((mu_p.mu_valid) == (mu_false)) ; 
}
              if (mu__boolexpr66) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 3;
        }
        else
          what_rule += 3;
    r = what_rule - 124;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_ReadReq, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_1_Value_undefined_var, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase14 ********************/
class RuleBase14
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    return tsprintf("Initial Read, n:%s, v:%s", mu_n.Name(), mu_v.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
  return (mu_p2.mu_state) == (mu_I);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 133;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    while (what_rule < 142 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
              if ((mu_p2.mu_state) == (mu_I)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 9;
        }
        else
          what_rule += 9;
    r = what_rule - 133;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_ReadReq, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_1_Value_undefined_var, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
/******************** RuleBase15 ********************/
class RuleBase15
{
public:
  int Priority()
  {
    return 0;
  }
  char * Name(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    return tsprintf("Initial L2 Allocation, n:%s, v:%s", mu_n.Name(), mu_v.Name());
  }
  bool Condition(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
  return (mu_p2.mu_state) == (mu_I);
  }

  void NextRule(unsigned & what_rule)
  {
    unsigned r = what_rule - 142;
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    while (what_rule < 151 )
      {
        if ( ( TRUE  ) ) {
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
              if ((mu_p2.mu_state) == (mu_I)) {
                if ( ( TRUE  ) )
                  return;
                else
                  what_rule++;
              }
              else
                what_rule += 9;
        }
        else
          what_rule += 9;
    r = what_rule - 142;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    mu_v.value((r % 3) + 4);
    r = r / 3;
    }
  }

  void Code(unsigned r)
  {
    static mu_1_Proc mu_n;
    mu_n.value((r % 3) + 1);
    r = r / 3;
    static mu_1_Value mu_v;
    mu_v.value((r % 3) + 4);
    r = r / 3;
  mu_1_L1State& mu_p = mu_L1[mu_n];
  mu_1_L2State& mu_p2 = mu_L2;
mu_Send ( mu_WriteReq, (int)mu_L2Type, (int)mu_n, mu_VC0, mu_v, mu_1_Count_undefined_var, mu_p.mu_EL );
  };

  bool UnFair()
  { return FALSE; }
};
class NextStateGenerator
{
  RuleBase0 R0;
  RuleBase1 R1;
  RuleBase2 R2;
  RuleBase3 R3;
  RuleBase4 R4;
  RuleBase5 R5;
  RuleBase6 R6;
  RuleBase7 R7;
  RuleBase8 R8;
  RuleBase9 R9;
  RuleBase10 R10;
  RuleBase11 R11;
  RuleBase12 R12;
  RuleBase13 R13;
  RuleBase14 R14;
  RuleBase15 R15;
public:
void SetNextEnabledRule(unsigned & what_rule)
{
  category = CONDITION;
  if (what_rule<16)
    { R0.NextRule(what_rule);
      if (what_rule<16) return; }
  if (what_rule>=16 && what_rule<25)
    { R1.NextRule(what_rule);
      if (what_rule<25) return; }
  if (what_rule>=25 && what_rule<34)
    { R2.NextRule(what_rule);
      if (what_rule<34) return; }
  if (what_rule>=34 && what_rule<43)
    { R3.NextRule(what_rule);
      if (what_rule<43) return; }
  if (what_rule>=43 && what_rule<52)
    { R4.NextRule(what_rule);
      if (what_rule<52) return; }
  if (what_rule>=52 && what_rule<61)
    { R5.NextRule(what_rule);
      if (what_rule<61) return; }
  if (what_rule>=61 && what_rule<70)
    { R6.NextRule(what_rule);
      if (what_rule<70) return; }
  if (what_rule>=70 && what_rule<79)
    { R7.NextRule(what_rule);
      if (what_rule<79) return; }
  if (what_rule>=79 && what_rule<88)
    { R8.NextRule(what_rule);
      if (what_rule<88) return; }
  if (what_rule>=88 && what_rule<97)
    { R9.NextRule(what_rule);
      if (what_rule<97) return; }
  if (what_rule>=97 && what_rule<106)
    { R10.NextRule(what_rule);
      if (what_rule<106) return; }
  if (what_rule>=106 && what_rule<115)
    { R11.NextRule(what_rule);
      if (what_rule<115) return; }
  if (what_rule>=115 && what_rule<124)
    { R12.NextRule(what_rule);
      if (what_rule<124) return; }
  if (what_rule>=124 && what_rule<133)
    { R13.NextRule(what_rule);
      if (what_rule<133) return; }
  if (what_rule>=133 && what_rule<142)
    { R14.NextRule(what_rule);
      if (what_rule<142) return; }
  if (what_rule>=142 && what_rule<151)
    { R15.NextRule(what_rule);
      if (what_rule<151) return; }
}
bool Condition(unsigned r)
{
  category = CONDITION;
  if (r<=15) return R0.Condition(r-0);
  if (r>=16 && r<=24) return R1.Condition(r-16);
  if (r>=25 && r<=33) return R2.Condition(r-25);
  if (r>=34 && r<=42) return R3.Condition(r-34);
  if (r>=43 && r<=51) return R4.Condition(r-43);
  if (r>=52 && r<=60) return R5.Condition(r-52);
  if (r>=61 && r<=69) return R6.Condition(r-61);
  if (r>=70 && r<=78) return R7.Condition(r-70);
  if (r>=79 && r<=87) return R8.Condition(r-79);
  if (r>=88 && r<=96) return R9.Condition(r-88);
  if (r>=97 && r<=105) return R10.Condition(r-97);
  if (r>=106 && r<=114) return R11.Condition(r-106);
  if (r>=115 && r<=123) return R12.Condition(r-115);
  if (r>=124 && r<=132) return R13.Condition(r-124);
  if (r>=133 && r<=141) return R14.Condition(r-133);
  if (r>=142 && r<=150) return R15.Condition(r-142);
Error.Notrace("Internal: NextStateGenerator -- checking condition for nonexisting rule.");
}
void Code(unsigned r)
{
  if (r<=15) { R0.Code(r-0); return; } 
  if (r>=16 && r<=24) { R1.Code(r-16); return; } 
  if (r>=25 && r<=33) { R2.Code(r-25); return; } 
  if (r>=34 && r<=42) { R3.Code(r-34); return; } 
  if (r>=43 && r<=51) { R4.Code(r-43); return; } 
  if (r>=52 && r<=60) { R5.Code(r-52); return; } 
  if (r>=61 && r<=69) { R6.Code(r-61); return; } 
  if (r>=70 && r<=78) { R7.Code(r-70); return; } 
  if (r>=79 && r<=87) { R8.Code(r-79); return; } 
  if (r>=88 && r<=96) { R9.Code(r-88); return; } 
  if (r>=97 && r<=105) { R10.Code(r-97); return; } 
  if (r>=106 && r<=114) { R11.Code(r-106); return; } 
  if (r>=115 && r<=123) { R12.Code(r-115); return; } 
  if (r>=124 && r<=132) { R13.Code(r-124); return; } 
  if (r>=133 && r<=141) { R14.Code(r-133); return; } 
  if (r>=142 && r<=150) { R15.Code(r-142); return; } 
}
int Priority(unsigned short r)
{
  if (r<=15) { return R0.Priority(); } 
  if (r>=16 && r<=24) { return R1.Priority(); } 
  if (r>=25 && r<=33) { return R2.Priority(); } 
  if (r>=34 && r<=42) { return R3.Priority(); } 
  if (r>=43 && r<=51) { return R4.Priority(); } 
  if (r>=52 && r<=60) { return R5.Priority(); } 
  if (r>=61 && r<=69) { return R6.Priority(); } 
  if (r>=70 && r<=78) { return R7.Priority(); } 
  if (r>=79 && r<=87) { return R8.Priority(); } 
  if (r>=88 && r<=96) { return R9.Priority(); } 
  if (r>=97 && r<=105) { return R10.Priority(); } 
  if (r>=106 && r<=114) { return R11.Priority(); } 
  if (r>=115 && r<=123) { return R12.Priority(); } 
  if (r>=124 && r<=132) { return R13.Priority(); } 
  if (r>=133 && r<=141) { return R14.Priority(); } 
  if (r>=142 && r<=150) { return R15.Priority(); } 
}
char * Name(unsigned r)
{
  if (r<=15) return R0.Name(r-0);
  if (r>=16 && r<=24) return R1.Name(r-16);
  if (r>=25 && r<=33) return R2.Name(r-25);
  if (r>=34 && r<=42) return R3.Name(r-34);
  if (r>=43 && r<=51) return R4.Name(r-43);
  if (r>=52 && r<=60) return R5.Name(r-52);
  if (r>=61 && r<=69) return R6.Name(r-61);
  if (r>=70 && r<=78) return R7.Name(r-70);
  if (r>=79 && r<=87) return R8.Name(r-79);
  if (r>=88 && r<=96) return R9.Name(r-88);
  if (r>=97 && r<=105) return R10.Name(r-97);
  if (r>=106 && r<=114) return R11.Name(r-106);
  if (r>=115 && r<=123) return R12.Name(r-115);
  if (r>=124 && r<=132) return R13.Name(r-124);
  if (r>=133 && r<=141) return R14.Name(r-133);
  if (r>=142 && r<=150) return R15.Name(r-142);
  return NULL;
}
};
const unsigned numrules = 151;

/********************
  parameter
 ********************/
#define RULES_IN_WORLD 151


/********************
  Startstate records
 ********************/
/******************** StartStateBase0 ********************/
class StartStateBase0
{
public:
  char * Name(unsigned short r)
  {
    return tsprintf("Startstate 0");
  }
  void Code(unsigned short r)
  {
{
for(int mu_v = 4; mu_v <= 6; mu_v++) {
mu_L2.mu_state = mu_I;
mu_L2.mu_shared = mu_false;
mu_L2.mu_written = mu_false;
mu_L2.mu_val = mu_v;
mu_L2.mu_EL = mu_false;
};
};
{
for(int mu_i = 1; mu_i <= 3; mu_i++) {
mu_L1[mu_i].mu_EL = mu_false;
mu_L1[mu_i].mu_valid = mu_false;
mu_L1[mu_i].mu_val.undefine();
};
};
mu_Net.undefine();
  };

  bool UnFair()
  { return FALSE; }
};
class StartStateGenerator
{
  StartStateBase0 S0;
public:
void Code(unsigned short r)
{
  if (r<=0) { S0.Code(r-0); return; }
}
char * Name(unsigned short r)
{
  if (r<=0) return S0.Name(r-0);
  return NULL;
}
};
unsigned short StartStateManager::numstartstates = 1;

/********************
  Invariant records
 ********************/
int mu__invariant_67() // Invariant "Values in L1 match L2 when SR state"
{
bool mu__quant68; 
mu__quant68 = TRUE;
{
for(int mu_p = 1; mu_p <= 3; mu_p++) {
bool mu__boolexpr69;
bool mu__boolexpr70;
  if (!((mu_L2.mu_state) == (mu_SR))) mu__boolexpr70 = FALSE ;
  else {
  mu__boolexpr70 = ((mu_L1[mu_p].mu_valid) == (mu_true)) ; 
}
  if (!(mu__boolexpr70)) mu__boolexpr69 = TRUE ;
  else {
  mu__boolexpr69 = ((mu_L1[mu_p].mu_val) == (mu_L2.mu_val)) ; 
}
if ( !(mu__boolexpr69) )
  { mu__quant68 = FALSE; break; }
};
};
return mu__quant68;
};

bool mu__condition_71() // Condition for Rule "Values in L1 match L2 when SR state"
{
  return mu__invariant_67( );
}

/**** end rule declaration ****/

int mu__invariant_72() // Invariant "Values in L1 match L2 when PR state"
{
bool mu__quant73; 
mu__quant73 = TRUE;
{
for(int mu_p = 1; mu_p <= 3; mu_p++) {
bool mu__boolexpr74;
bool mu__boolexpr75;
  if (!((mu_L2.mu_state) == (mu_PR))) mu__boolexpr75 = FALSE ;
  else {
  mu__boolexpr75 = ((mu_L1[mu_p].mu_EL) == (mu_true)) ; 
}
  if (!(mu__boolexpr75)) mu__boolexpr74 = TRUE ;
  else {
  mu__boolexpr74 = ((mu_L1[mu_p].mu_val) == (mu_L2.mu_val)) ; 
}
if ( !(mu__boolexpr74) )
  { mu__quant73 = FALSE; break; }
};
};
return mu__quant73;
};

bool mu__condition_76() // Condition for Rule "Values in L1 match L2 when PR state"
{
  return mu__invariant_72( );
}

/**** end rule declaration ****/

int mu__invariant_77() // Invariant "Modified state exclusivity"
{
bool mu__boolexpr78;
  if (!((mu_L2.mu_state) == (mu_SW))) mu__boolexpr78 = TRUE ;
  else {
bool mu__quant79; 
mu__quant79 = TRUE;
{
for(int mu_p = 1; mu_p <= 3; mu_p++) {
bool mu__boolexpr80;
bool mu__boolexpr81;
  if (!((mu_L1[mu_p].mu_valid) == (mu_false))) mu__boolexpr81 = FALSE ;
  else {
  mu__boolexpr81 = ((mu_L1[mu_p].mu_EL) == (mu_false)) ; 
}
  if (!(mu__boolexpr81)) mu__boolexpr80 = FALSE ;
  else {
  mu__boolexpr80 = ((mu_L2.mu_EL) == (mu_true)) ; 
}
if ( !(mu__boolexpr80) )
  { mu__quant79 = FALSE; break; }
};
};
  mu__boolexpr78 = (mu__quant79) ; 
}
return mu__boolexpr78;
};

bool mu__condition_82() // Condition for Rule "Modified state exclusivity"
{
  return mu__invariant_77( );
}

/**** end rule declaration ****/

int mu__invariant_83() // Invariant "L2_only state consistency"
{
bool mu__quant84; 
mu__quant84 = TRUE;
{
for(int mu_p = 1; mu_p <= 3; mu_p++) {
bool mu__boolexpr85;
  if (!((mu_L2.mu_state) == (mu_L2_only))) mu__boolexpr85 = TRUE ;
  else {
bool mu__boolexpr86;
  if (!((mu_L1[mu_p].mu_valid) == (mu_false))) mu__boolexpr86 = FALSE ;
  else {
  mu__boolexpr86 = ((mu_L1[mu_p].mu_EL) == (mu_false)) ; 
}
  mu__boolexpr85 = (mu__boolexpr86) ; 
}
if ( !(mu__boolexpr85) )
  { mu__quant84 = FALSE; break; }
};
};
return mu__quant84;
};

bool mu__condition_87() // Condition for Rule "L2_only state consistency"
{
  return mu__invariant_83( );
}

/**** end rule declaration ****/

int mu__invariant_88() // Invariant "At most one EL flag is true in the system - 1"
{
bool mu__boolexpr89;
bool mu__boolexpr90;
bool mu__boolexpr91;
bool mu__boolexpr92;
  if ((mu_L2.mu_state) == (mu_PR)) mu__boolexpr92 = TRUE ;
  else {
  mu__boolexpr92 = ((mu_L2.mu_state) == (mu_PRW)) ; 
}
  if (mu__boolexpr92) mu__boolexpr91 = TRUE ;
  else {
  mu__boolexpr91 = ((mu_L2.mu_state) == (mu_L2_only)) ; 
}
  if (mu__boolexpr91) mu__boolexpr90 = TRUE ;
  else {
  mu__boolexpr90 = ((mu_L2.mu_state) == (mu_SW)) ; 
}
  if (!(mu__boolexpr90)) mu__boolexpr89 = TRUE ;
  else {
  mu__boolexpr89 = ((mu_Sumfunc(  )) == (1)) ; 
}
return mu__boolexpr89;
};

bool mu__condition_93() // Condition for Rule "At most one EL flag is true in the system - 1"
{
  return mu__invariant_88( );
}

/**** end rule declaration ****/

int mu__invariant_94() // Invariant "At most zero EL flag is true in the system - 0"
{
bool mu__boolexpr95;
bool mu__boolexpr96;
  if ((mu_L2.mu_state) == (mu_I)) mu__boolexpr96 = TRUE ;
  else {
  mu__boolexpr96 = ((mu_L2.mu_state) == (mu_SR)) ; 
}
  if (!(mu__boolexpr96)) mu__boolexpr95 = TRUE ;
  else {
  mu__boolexpr95 = ((mu_Sumfunc(  )) == (0)) ; 
}
return mu__boolexpr95;
};

bool mu__condition_97() // Condition for Rule "At most zero EL flag is true in the system - 0"
{
  return mu__invariant_94( );
}

/**** end rule declaration ****/

const rulerec invariants[] = {
{"At most zero EL flag is true in the system - 0", &mu__condition_97, NULL, FALSE},
{"At most one EL flag is true in the system - 1", &mu__condition_93, NULL, FALSE},
{"L2_only state consistency", &mu__condition_87, NULL, FALSE},
{"Modified state exclusivity", &mu__condition_82, NULL, FALSE},
{"Values in L1 match L2 when PR state", &mu__condition_76, NULL, FALSE},
{"Values in L1 match L2 when SR state", &mu__condition_71, NULL, FALSE},
};
const unsigned short numinvariants = 6;

/******************/
bool mu__true_live() { return TRUE; }
/******************/

/********************
  Liveness records
 ********************/
const liverec livenesses[] = {
{ NULL, NULL, NULL, NULL, E }};
const unsigned short numlivenesses = 0;

/********************
  Fairstates records
 ********************/
const rulerec fairnesses[] = {
{ NULL, NULL, NULL, FALSE }};
const unsigned short numfairnesses = 0;

/********************
  Normal/Canonicalization for scalarset
 ********************/
/*
msg_processed:NoScalarset
SumV:NoScalarset
LastWrite:ScalarsetVariable
L2:ScalarsetVariable
InBox:ScalarsetArrayOfScalarset
L1:ScalarsetArrayOfScalarset
Net:Complex
*/

/********************
Code for symmetry
 ********************/

/********************
 Permutation Set Class
 ********************/
class PermSet
{
public:
  // book keeping
  enum PresentationType {Simple, Explicit};
  PresentationType Presentation;

  void ResetToSimple();
  void ResetToExplicit();
  void SimpleToExplicit();
  void SimpleToOne();
  bool NextPermutation();

  void Print_in_size()
  { int ret=0; for (int i=0; i<count; i++) if (in[i]) ret++; cout << "in_size:" << ret << "\n"; }


  /********************
   Simple and efficient representation
   ********************/
  int class_mu_1_Value[3];
  int undefined_class_mu_1_Value;// has the highest class number

  void Print_class_mu_1_Value();
  bool OnlyOneRemain_mu_1_Value;
  bool MTO_class_mu_1_Value()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_Value)
      return FALSE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_Value[i]== class_mu_1_Value[j])
	    return TRUE;
    OnlyOneRemain_mu_1_Value = TRUE;
    return FALSE;
  }
  int class_mu_1_Proc[3];
  int undefined_class_mu_1_Proc;// has the highest class number

  void Print_class_mu_1_Proc();
  bool OnlyOneRemain_mu_1_Proc;
  bool MTO_class_mu_1_Proc()
  {
    int i,j;
    if (OnlyOneRemain_mu_1_Proc)
      return FALSE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_Proc[i]== class_mu_1_Proc[j])
	    return TRUE;
    OnlyOneRemain_mu_1_Proc = TRUE;
    return FALSE;
  }
  bool AlreadyOnlyOneRemain;
  bool MoreThanOneRemain();


  /********************
   Explicit representation
  ********************/
  unsigned long size;
  unsigned long count;
  // in will be of product of factorial sizes for fast canonicalize
  // in will be of size 1 for reduced local memory canonicalize
  bool * in;

  // auxiliary for explicit representation

  // in/perm/revperm will be of factorial size for fast canonicalize
  // they will be of size 1 for reduced local memory canonicalize
  // second range will be size of the scalarset
  int * in_mu_1_Value;
  typedef int arr_mu_1_Value[3];
  arr_mu_1_Value * perm_mu_1_Value;
  arr_mu_1_Value * revperm_mu_1_Value;

  int size_mu_1_Value[3];
  bool reversed_sorted_mu_1_Value(int start, int end);
  void reverse_reversed_mu_1_Value(int start, int end);

  int * in_mu_1_Proc;
  typedef int arr_mu_1_Proc[3];
  arr_mu_1_Proc * perm_mu_1_Proc;
  arr_mu_1_Proc * revperm_mu_1_Proc;

  int size_mu_1_Proc[3];
  bool reversed_sorted_mu_1_Proc(int start, int end);
  void reverse_reversed_mu_1_Proc(int start, int end);

  // procedure for explicit representation
  bool ok0(mu_1_Value* perm, int size, mu_1_Value k);
  void GenPerm0(mu_1_Value* perm, int size, unsigned long& index);

  bool ok1(mu_1_Proc* perm, int size, mu_1_Proc k);
  void GenPerm1(mu_1_Proc* perm, int size, unsigned long& index);

  // General procedure
  PermSet();
  bool In(int i) const { return in[i]; };
  void Add(int i) { for (int j=0; j<i; j++) in[j] = FALSE;};
  void Remove(int i) { in[i] = FALSE; };
};
void PermSet::Print_class_mu_1_Value()
{
  cout << "class_mu_1_Value:\t";
  for (int i=0; i<3; i++)
    cout << class_mu_1_Value[i];
  cout << " " << undefined_class_mu_1_Value << "\n";
}
void PermSet::Print_class_mu_1_Proc()
{
  cout << "class_mu_1_Proc:\t";
  for (int i=0; i<3; i++)
    cout << class_mu_1_Proc[i];
  cout << " " << undefined_class_mu_1_Proc << "\n";
}
bool PermSet::MoreThanOneRemain()
{
  int i,j;
  if (AlreadyOnlyOneRemain)
    return FALSE;
  else {
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_Value[i]== class_mu_1_Value[j])
	    return TRUE;
    for (i=0; i<3; i++)
      for (j=0; j<3; j++)
        if (i!=j && class_mu_1_Proc[i]== class_mu_1_Proc[j])
	    return TRUE;
  }
  AlreadyOnlyOneRemain = TRUE;
  return FALSE;
}
PermSet::PermSet()
: Presentation(Simple)
{
  int i,j,k;
  if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
     || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
    mu_1_Value Perm0[3];
    mu_1_Proc Perm1[3];

  /********************
   declaration of class variables
  ********************/
  in = new bool[36];
 in_mu_1_Value = new int[36];
 perm_mu_1_Value = new arr_mu_1_Value[6];
 revperm_mu_1_Value = new arr_mu_1_Value[6];
 in_mu_1_Proc = new int[36];
 perm_mu_1_Proc = new arr_mu_1_Proc[6];
 revperm_mu_1_Proc = new arr_mu_1_Proc[6];

    // Set perm and revperm
    count = 0;
    for (i=4; i<=6; i++)
      {
        Perm0[0].value(i);
        GenPerm0(Perm0, 1, count);
      }
    if (count!=6)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<6; i++)
      for (j=4; j<=6; j++)
        for (k=4; k<=6; k++)
          if (revperm_mu_1_Value[i][k-4]==j)   // k - base 
            perm_mu_1_Value[i][j-4]=k; // j - base 
    count = 0;
    for (i=1; i<=3; i++)
      {
        Perm1[0].value(i);
        GenPerm1(Perm1, 1, count);
      }
    if (count!=6)
      Error.Error( "unable to initialize PermSet");
    for (i=0; i<6; i++)
      for (j=1; j<=3; j++)
        for (k=1; k<=3; k++)
          if (revperm_mu_1_Proc[i][k-1]==j)   // k - base 
            perm_mu_1_Proc[i][j-1]=k; // j - base 

    // setting up combination of permutations
    // for different scalarset
    int carry;
    int i_mu_1_Value = 0;
    int i_mu_1_Proc = 0;
    size = 36;
    count = 36;
    for (i=0; i<36; i++)
      {
        carry = 1;
        in[i]= TRUE;
      in_mu_1_Value[i] = i_mu_1_Value;
      i_mu_1_Value += carry;
      if (i_mu_1_Value >= 6) { i_mu_1_Value = 0; carry = 1; } 
      else { carry = 0; } 
      in_mu_1_Proc[i] = i_mu_1_Proc;
      i_mu_1_Proc += carry;
      if (i_mu_1_Proc >= 6) { i_mu_1_Proc = 0; carry = 1; } 
      else { carry = 0; } 
    }
  }
  else
  {

  /********************
   declaration of class variables
  ********************/
  in = new bool[1];
 in_mu_1_Value = new int[1];
 perm_mu_1_Value = new arr_mu_1_Value[1];
 revperm_mu_1_Value = new arr_mu_1_Value[1];
 in_mu_1_Proc = new int[1];
 perm_mu_1_Proc = new arr_mu_1_Proc[1];
 revperm_mu_1_Proc = new arr_mu_1_Proc[1];
  in[0] = TRUE;
    in_mu_1_Value[0] = 0;
    in_mu_1_Proc[0] = 0;
  }
}
void PermSet::ResetToSimple()
{
  int i;
  for (i=0; i<3; i++)
    class_mu_1_Value[i]=0;
  undefined_class_mu_1_Value=0;
  OnlyOneRemain_mu_1_Value = FALSE;
  for (i=0; i<3; i++)
    class_mu_1_Proc[i]=0;
  undefined_class_mu_1_Proc=0;
  OnlyOneRemain_mu_1_Proc = FALSE;

  AlreadyOnlyOneRemain = FALSE;
  Presentation = Simple;
}
void PermSet::ResetToExplicit()
{
  for (int i=0; i<36; i++) in[i] = TRUE;
  Presentation = Explicit;
}
void PermSet::SimpleToExplicit()
{
  int i,j,k;
  int start, class_size;
  int start_mu_1_Value[3];
  int size_mu_1_Value[3];
  bool should_be_in_mu_1_Value[6];
  int start_mu_1_Proc[3];
  int size_mu_1_Proc[3];
  bool should_be_in_mu_1_Proc[6];

  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Value; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  {
	    size_mu_1_Value[k] = class_size;
	    start_mu_1_Value[k] = start;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  {
	    size_mu_1_Proc[k] = class_size;
	    start_mu_1_Proc[k] = start;
	  }
      start+=class_size;
    }

  // To be In or not to be
  for (i=0; i<6; i++) // set up
    should_be_in_mu_1_Value[i] = TRUE;
  for (i=0; i<6; i++) // to be in or not to be
    for (k=0; k<3; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_Value[i][k]-4 >=start_mu_1_Value[k] 
	     && perm_mu_1_Value[i][k]-4 < start_mu_1_Value[k] + size_mu_1_Value[k]) )
  	    {
	      should_be_in_mu_1_Value[i] = FALSE;
	      break;
	    }
  for (i=0; i<6; i++) // set up
    should_be_in_mu_1_Proc[i] = TRUE;
  for (i=0; i<6; i++) // to be in or not to be
    for (k=0; k<3; k++) // step through class_mu_1_pid[k]
      if (! (perm_mu_1_Proc[i][k]-1 >=start_mu_1_Proc[k] 
	     && perm_mu_1_Proc[i][k]-1 < start_mu_1_Proc[k] + size_mu_1_Proc[k]) )
  	    {
	      should_be_in_mu_1_Proc[i] = FALSE;
	      break;
	    }

  // setup explicit representation 
  // Set perm and revperm
  for (i=0; i<36; i++)
    {
      in[i] = TRUE;
      if (in[i] && !should_be_in_mu_1_Value[in_mu_1_Value[i]]) in[i] = FALSE;
      if (in[i] && !should_be_in_mu_1_Proc[in_mu_1_Proc[i]]) in[i] = FALSE;
    }
  Presentation = Explicit;
  if (args->test_parameter1.value==0) Print_in_size();
}
void PermSet::SimpleToOne()
{
  int i,j,k;
  int class_size;
  int start;


  // Setup range for mapping
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Value; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Value[k]==j)
	  {
	    size_mu_1_Value[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      class_size = 0;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  class_size++;
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	if (class_mu_1_Proc[k]==j)
	  {
	    size_mu_1_Proc[k] = class_size;
	  }
      start+=class_size;
    }
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Value; j++) // class number
    {
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_Value[k]==j)
	      revperm_mu_1_Value[0][start++] = k+4;
    }
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_Value[0][k]==j+4)
        perm_mu_1_Value[0][j]=k+4;
  start = 0;
  for (j=0; j<=undefined_class_mu_1_Proc; j++) // class number
    {
      for (k=0; k<3; k++) // step through class_mu_1_pid[k]
	    if (class_mu_1_Proc[k]==j)
	      revperm_mu_1_Proc[0][start++] = k+1;
    }
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_Proc[0][k]==j+1)
        perm_mu_1_Proc[0][j]=k+1;
  Presentation = Explicit;
}
bool PermSet::ok0(mu_1_Value* Perm, int size, mu_1_Value k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm0(mu_1_Value* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=3)
    {
      for (i=4; i<=6; i++)
        if(ok0(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm0(Perm, size+1, count);
          }
    }
  else
    {
      for (i=4; i<=6; i++)
        revperm_mu_1_Value[count][i-4]=Perm[i-4].value();// i - base
      count++;
    }
}
bool PermSet::ok1(mu_1_Proc* Perm, int size, mu_1_Proc k)
{
  for (int i=0; i<size; i++)
    if(Perm[i].value()==k)
      return FALSE;
  return TRUE;
}
void PermSet::GenPerm1(mu_1_Proc* Perm,int size, unsigned long& count)
{
  int i;
  if (size!=3)
    {
      for (i=1; i<=3; i++)
        if(ok1(Perm,size,i))
          {
            Perm[size].value(i);
            GenPerm1(Perm, size+1, count);
          }
    }
  else
    {
      for (i=1; i<=3; i++)
        revperm_mu_1_Proc[count][i-1]=Perm[i-1].value();// i - base
      count++;
    }
}
bool PermSet::reversed_sorted_mu_1_Value(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_Value[0][i]<revperm_mu_1_Value[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_Value(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_Value[0][j];
      revperm_mu_1_Value[0][j] = revperm_mu_1_Value[0][i];
      revperm_mu_1_Value[0][i] = temp;
    }
}
bool PermSet::reversed_sorted_mu_1_Proc(int start, int end)
{
  int i,j;

  for (i=start; i<end; i++)
    if (revperm_mu_1_Proc[0][i]<revperm_mu_1_Proc[0][i+1])
      return FALSE;
  return TRUE;
}
void PermSet::reverse_reversed_mu_1_Proc(int start, int end)
{
  int i,j;
  int temp;

  for (i=start, j=end; i<j; i++,j--) 
    {
      temp = revperm_mu_1_Proc[0][j];
      revperm_mu_1_Proc[0][j] = revperm_mu_1_Proc[0][i];
      revperm_mu_1_Proc[0][i] = temp;
    }
}
bool PermSet::NextPermutation()
{
  bool nexted = FALSE;
  int start, end; 
  int class_size;
  int temp;
  int j,k;

  // algorithm
  // for each class
  //   if forall in the same class reverse_sorted, 
  //     { sort again; goto next class }
  //   else
  //     {
  //       nexted = TRUE;
  //       for (j from l to r)
  // 	       if (for all j+ are reversed sorted)
  // 	         {
  // 	           swap j, j+1
  // 	           sort all j+ again
  // 	           break;
  // 	         }
  //     }
  for (start = 0; start < 3; )
    {
      end = start-1+size_mu_1_Value[revperm_mu_1_Value[0][start]-4];
      if (reversed_sorted_mu_1_Value(start,end))
	       {
	  reverse_reversed_mu_1_Value(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_Value(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_Value[0][j]<revperm_mu_1_Value[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_Value[0][j];
			  revperm_mu_1_Value[0][j] = revperm_mu_1_Value[0][k];
			  revperm_mu_1_Value[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_Value(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
if (!nexted) {
  for (start = 0; start < 3; )
    {
      end = start-1+size_mu_1_Proc[revperm_mu_1_Proc[0][start]-1];
      if (reversed_sorted_mu_1_Proc(start,end))
	       {
	  reverse_reversed_mu_1_Proc(start,end);
	  start = end+1;
	}
      else
	{
	  nexted = TRUE;
	  for (j = start; j<end; j++)
	    {
	      if (reversed_sorted_mu_1_Proc(j+1,end))
		{
		  for (k = end; k>j; k--)
		    {
		      if (revperm_mu_1_Proc[0][j]<revperm_mu_1_Proc[0][k])
			{
			  // swap j, k
			  temp = revperm_mu_1_Proc[0][j];
			  revperm_mu_1_Proc[0][j] = revperm_mu_1_Proc[0][k];
			  revperm_mu_1_Proc[0][k] = temp;
			  break;
			}
		    }
		  reverse_reversed_mu_1_Proc(j+1,end);
		  break;
		}
	    }
	  break;
	}
    }
}
if (!nexted) return FALSE;
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_Value[0][k]==j+4)   // k - base 
	perm_mu_1_Value[0][j]=k+4; // j - base 
  for (j=0; j<3; j++)
    for (k=0; k<3; k++)
      if (revperm_mu_1_Proc[0][k]==j+1)   // k - base 
	perm_mu_1_Proc[0][j]=k+1; // j - base 
  return TRUE;
}

/********************
 Symmetry Class
 ********************/
class SymmetryClass
{
  PermSet Perm;
  bool BestInitialized;
  state BestPermutedState;

  // utilities
  void SetBestResult(int i, state* temp);
  void ResetBestResult() {BestInitialized = FALSE;};

public:
  // initializer
  SymmetryClass() : Perm(), BestInitialized(FALSE) {};
  ~SymmetryClass() {};

  void Normalize(state* s);

  void Exhaustive_Fast_Canonicalize(state *s);
  void Heuristic_Fast_Canonicalize(state *s);
  void Heuristic_Small_Mem_Canonicalize(state *s);
  void Heuristic_Fast_Normalize(state *s);

  void MultisetSort(state* s);
};


/********************
 Symmetry Class Members
 ********************/
void SymmetryClass::MultisetSort(state* s)
{
        mu_msg_processed.MultisetSort();
        mu_SumV.MultisetSort();
        mu_LastWrite.MultisetSort();
        mu_L2.MultisetSort();
        mu_InBox.MultisetSort();
        mu_L1.MultisetSort();
        mu_Net.MultisetSort();
}
void SymmetryClass::Normalize(state* s)
{
  switch (args->sym_alg.mode) {
  case argsym_alg::Exhaustive_Fast_Canonicalize:
    Exhaustive_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Canonicalize:
    Heuristic_Fast_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Small_Mem_Canonicalize:
    Heuristic_Small_Mem_Canonicalize(s);
    break;
  case argsym_alg::Heuristic_Fast_Normalize:
    Heuristic_Fast_Normalize(s);
    break;
  default:
    Heuristic_Fast_Canonicalize(s);
  }
}

/********************
 Permute and Canonicalize function for different types
 ********************/
void mu_1_Proc::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_Proc[Perm.in_mu_1_Proc[i]][value()-1]); // value - base
};
void mu_1_Proc::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
            Perm.class_mu_1_Proc[i]++;
        value(1 + Perm.undefined_class_mu_1_Proc++);
      }
    else 
      {
        value(Perm.class_mu_1_Proc[value()-1]+1);
      }
}
void mu_1_Proc::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Proc::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
            Perm.class_mu_1_Proc[i]++;
        Perm.undefined_class_mu_1_Proc++;
      }
}
void mu_1_Proc::ArrayLimit(PermSet& Perm) {}
void mu_1_Proc::Limit(PermSet& Perm) {}
void mu_1_Proc::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_Value::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined())
    value(Perm.perm_mu_1_Value[Perm.in_mu_1_Value[i]][value()-4]); // value - base
};
void mu_1_Value::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Value[value()-4]==Perm.undefined_class_mu_1_Value) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_Value[i] == Perm.undefined_class_mu_1_Value && i!=value()-4)
            Perm.class_mu_1_Value[i]++;
        value(4 + Perm.undefined_class_mu_1_Value++);
      }
    else 
      {
        value(Perm.class_mu_1_Value[value()-4]+4);
      }
}
void mu_1_Value::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Value::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");

  if (defined())
    if (Perm.class_mu_1_Value[value()-4]==Perm.undefined_class_mu_1_Value) // value - base
      {
        // it has not been mapped to any particular value
        for (i=0; i<3; i++)
          if (Perm.class_mu_1_Value[i] == Perm.undefined_class_mu_1_Value && i!=value()-4)
            Perm.class_mu_1_Value[i]++;
        Perm.undefined_class_mu_1_Value++;
      }
}
void mu_1_Value::ArrayLimit(PermSet& Perm) {}
void mu_1_Value::Limit(PermSet& Perm) {}
void mu_1_Value::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset type.\n"); };
void mu_1_L2_cache::Permute(PermSet& Perm, int i) {};
void mu_1_L2_cache::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_L2_cache::Canonicalize(PermSet& Perm) {};
void mu_1_L2_cache::SimpleLimit(PermSet& Perm) {};
void mu_1_L2_cache::ArrayLimit(PermSet& Perm) {};
void mu_1_L2_cache::Limit(PermSet& Perm) {};
void mu_1_L2_cache::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Node::Permute(PermSet& Perm, int i)
{
  if (Perm.Presentation != PermSet::Explicit)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 3 ) )
      value(Perm.perm_mu_1_Proc[Perm.in_mu_1_Proc[i]][value()-1]+(0)); // value - base
  }
}
void mu_1_Node::SimpleCanonicalize(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 3 ) )
      {
        if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
          {
            // it has not been mapped to any particular value
            for (i=0; i<3; i++)
              if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
                Perm.class_mu_1_Proc[i]++;
            value(1 + Perm.undefined_class_mu_1_Proc++);
          }
        else 
          {
            value(Perm.class_mu_1_Proc[value()-1]+1);
          }
      }
  }
}
void mu_1_Node::Canonicalize(PermSet& Perm)
{
  Error.Error("Calling canonicalize() for Scalarset.");
}
void mu_1_Node::SimpleLimit(PermSet& Perm)
{
  int i, class_number;
  if (Perm.Presentation != PermSet::Simple)
    Error.Error("Internal Error: Wrong Sequence of Normalization");
  if (defined()) {
    if ( ( value() >= 1 ) && ( value() <= 3 ) )
      if (Perm.class_mu_1_Proc[value()-1]==Perm.undefined_class_mu_1_Proc) // value - base
        {
          // it has not been mapped to any particular value
          for (i=0; i<3; i++)
            if (Perm.class_mu_1_Proc[i] == Perm.undefined_class_mu_1_Proc && i!=value()-1)
              Perm.class_mu_1_Proc[i]++;
          Perm.undefined_class_mu_1_Proc++;
        }
  }
}
void mu_1_Node::ArrayLimit(PermSet& Perm) {}
void mu_1_Node::Limit(PermSet& Perm) {}
void mu_1_Node::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for union type.\n"); };
void mu_1_Count::Permute(PermSet& Perm, int i) {};
void mu_1_Count::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Count::Canonicalize(PermSet& Perm) {};
void mu_1_Count::SimpleLimit(PermSet& Perm) {};
void mu_1_Count::ArrayLimit(PermSet& Perm) {};
void mu_1_Count::Limit(PermSet& Perm) {};
void mu_1_Count::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_Sum::Permute(PermSet& Perm, int i) {};
void mu_1_Sum::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_Sum::Canonicalize(PermSet& Perm) {};
void mu_1_Sum::SimpleLimit(PermSet& Perm) {};
void mu_1_Sum::ArrayLimit(PermSet& Perm) {};
void mu_1_Sum::Limit(PermSet& Perm) {};
void mu_1_Sum::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_VCType::Permute(PermSet& Perm, int i) {};
void mu_1_VCType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_VCType::Canonicalize(PermSet& Perm) {};
void mu_1_VCType::SimpleLimit(PermSet& Perm) {};
void mu_1_VCType::ArrayLimit(PermSet& Perm) {};
void mu_1_VCType::Limit(PermSet& Perm) {};
void mu_1_VCType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for subrange type.\n"); };
void mu_1_MessageType::Permute(PermSet& Perm, int i) {};
void mu_1_MessageType::SimpleCanonicalize(PermSet& Perm) {};
void mu_1_MessageType::Canonicalize(PermSet& Perm) {};
void mu_1_MessageType::SimpleLimit(PermSet& Perm) {};
void mu_1_MessageType::ArrayLimit(PermSet& Perm) {};
void mu_1_MessageType::Limit(PermSet& Perm) {};
void mu_1_MessageType::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_Message::Permute(PermSet& Perm, int i)
{
  mu_src.Permute(Perm,i);
  mu_val.Permute(Perm,i);
};
void mu_1_Message::SimpleCanonicalize(PermSet& Perm)
{
  mu_src.SimpleCanonicalize(Perm);
  mu_val.SimpleCanonicalize(Perm);
};
void mu_1_Message::Canonicalize(PermSet& Perm)
{
};
void mu_1_Message::SimpleLimit(PermSet& Perm)
{
  mu_src.SimpleLimit(Perm);
  mu_val.SimpleLimit(Perm);
};
void mu_1_Message::ArrayLimit(PermSet& Perm){}
void mu_1_Message::Limit(PermSet& Perm)
{
};
void mu_1_Message::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_0::Permute(PermSet& Perm, int i) {};
void mu_1__type_0::SimpleCanonicalize(PermSet& Perm) {};
void mu_1__type_0::Canonicalize(PermSet& Perm) {};
void mu_1__type_0::SimpleLimit(PermSet& Perm) {};
void mu_1__type_0::ArrayLimit(PermSet& Perm) {};
void mu_1__type_0::Limit(PermSet& Perm) {};
void mu_1__type_0::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for enum type.\n"); };
void mu_1_L2State::Permute(PermSet& Perm, int i)
{
  mu_val.Permute(Perm,i);
};
void mu_1_L2State::SimpleCanonicalize(PermSet& Perm)
{
  mu_val.SimpleCanonicalize(Perm);
};
void mu_1_L2State::Canonicalize(PermSet& Perm)
{
};
void mu_1_L2State::SimpleLimit(PermSet& Perm)
{
  mu_val.SimpleLimit(Perm);
};
void mu_1_L2State::ArrayLimit(PermSet& Perm){}
void mu_1_L2State::Limit(PermSet& Perm)
{
};
void mu_1_L2State::MultisetLimit(PermSet& Perm)
{
};
void mu_1_L1State::Permute(PermSet& Perm, int i)
{
  mu_val.Permute(Perm,i);
};
void mu_1_L1State::SimpleCanonicalize(PermSet& Perm)
{
  mu_val.SimpleCanonicalize(Perm);
};
void mu_1_L1State::Canonicalize(PermSet& Perm)
{
};
void mu_1_L1State::SimpleLimit(PermSet& Perm)
{
  mu_val.SimpleLimit(Perm);
};
void mu_1_L1State::ArrayLimit(PermSet& Perm){}
void mu_1_L1State::Limit(PermSet& Perm)
{
};
void mu_1_L1State::MultisetLimit(PermSet& Perm)
{
};
void mu_1__type_1::Permute(PermSet& Perm, int i)
{
  static mu_1__type_1 temp("Permute_mu_1__type_1",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=3; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Proc[Perm.in_mu_1_Proc[i]][j-1]];};
void mu_1__type_1::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_1::Canonicalize(PermSet& Perm){};
void mu_1__type_1::SimpleLimit(PermSet& Perm){}
void mu_1__type_1::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int count_mu_1_Proc;
  int compare;
  static mu_1_L1State value[3];
  // limit
  bool exists;
  bool split;
  bool goodset_mu_1_Proc[3];
  bool pos_mu_1_Proc[3][3];
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<3; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<3; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
}
void mu_1__type_1::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_L1State value[3];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[3][3];
  bool goodset_mu_1_Proc[3];
  int count_mu_1_Value, oldcount_mu_1_Value;
  bool pos_mu_1_Value[3][3];
  bool goodset_mu_1_Value[3];
  // count_ corresponds to the number of equivalence class within the
  // scalarset value.  If count_ == size of the scalarset, then a unique
  // permutation has been found.

  // pos_ is a relation on a equivalence class number and a scalarset value.

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }
  // count_ corresponds to the number of equivalence class within the
  // scalarset value.  If count_ == size of the scalarset, then a unique
  // permutation has been found.

  // pos_ is a relation on a equivalence class number and a scalarset value.

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_Value[i][j]=FALSE;
  count_mu_1_Value = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_Value[i] == count_mu_1_Value)
         {
           pos_mu_1_Value[count_mu_1_Value][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Value++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Value() && count_mu_1_Value<3);
  while ( while_guard )
    {
      oldcount_mu_1_Proc = count_mu_1_Proc;
      oldcount_mu_1_Value = count_mu_1_Value;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
           || ( Perm.MTO_class_mu_1_Value() && count_mu_1_Value<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if ((*this)[k+1].mu_val.isundefined())
              exists = TRUE;
            else
              split = TRUE;
          if (exists && split)
            {
              for (i=0; i<count_mu_1_Proc; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Value; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Value[k] = FALSE;
                    for (k=0; k<3; k++) // scan array index
                      // set goodsets
                      if (pos_mu_1_Proc[i][k] 
                          && !(*this)[k+1].mu_val.isundefined()
                          && pos_mu_1_Value[j][(*this)[k+1].mu_val-4])
                        {
                          exists = TRUE;
                          goodset_mu_1_Proc[k] = TRUE;
                          goodset_mu_1_Value[(*this)[k+1].mu_val-4] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>i; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i][k] = FALSE;
                                if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Value; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Value[z][k] = pos_mu_1_Value[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j][k] = FALSE;
                                if (pos_mu_1_Value[j+1][k] && goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j+1][k] = FALSE;
                              }
                            count_mu_1_Value++;
                          }
                      }
                  }
            }
        }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard = while_guard || (oldcount_mu_1_Value!=count_mu_1_Value);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_Proc<3;
      while_guard = while_guard || count_mu_1_Value<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
  // enter the result into class
  if (Perm.MTO_class_mu_1_Value())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_Value[i][j])
            Perm.class_mu_1_Value[j] = i;
      Perm.undefined_class_mu_1_Value=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_Value[j]>Perm.undefined_class_mu_1_Value)
          Perm.undefined_class_mu_1_Value=Perm.class_mu_1_Value[j];
    }
}
void mu_1__type_1::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_2::Permute(PermSet& Perm, int i)
{
  static mu_1__type_2 temp("Permute_mu_1__type_2",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_2::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: calling SimpleCanonicalize for a multiset.\n"); };
void mu_1__type_2::Canonicalize(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::SimpleLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::ArrayLimit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::Limit(PermSet& Perm)
{ Error.Error("You cannot use this symmetry algorithm with Multiset.\n"); };
void mu_1__type_2::MultisetLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1_Message value[4];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Value, oldcount_mu_1_Value;
  bool pos_mu_1_Value[3][3];
  bool goodset_mu_1_Value[3];
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[3][3];
  bool goodset_mu_1_Proc[3];
  int count_multisetindex, oldcount_multisetindex;
  bool pos_multisetindex[4][4];
  bool goodset_multisetindex[4];
  mu_1_Message temp;

  // compact
  for (i = 0, j = 0; i < 4; i++)
    if (valid[i].value())
      {
        if (j!=i)
          array[j++] = array[i];
        else
          j++;
      }
  if (j != current_size) current_size = j;
  for (i = j; i < 4; i++)
    array[i].undefine();
  for (i = 0; i < j; i++)
    valid[i].value(TRUE);
  for (i = j; i < 4; i++)
    valid[i].value(FALSE);

  // bubble sort
  for (i = 0; i < current_size; i++)
    for (j = i+1; j < current_size; j++)
      if (CompareWeight(array[i],array[j])>0)
        {
          temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }
  // initializing pos array
    for (i=0; i<current_size; i++)
      for (j=0; j<current_size; j++)
        pos_multisetindex[i][j]=FALSE;
    count_multisetindex = 1;
    pos_multisetindex[0][0] = TRUE;
    for (i = 1, j = 0 ; i < current_size; i++)
      if (CompareWeight(array[i-1],array[i])==0)
        pos_multisetindex[j][i] = TRUE;
      else
        { count_multisetindex++; pos_multisetindex[++j][i] = TRUE; }
  if (current_size == 1)
    {
      array[0].SimpleLimit(Perm);
    }
  else
    {

  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_Value[i][j]=FALSE;
  count_mu_1_Value = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_Value[i] == count_mu_1_Value)
         {
           pos_mu_1_Value[count_mu_1_Value][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Value++;
      else break;
    }
  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }

  // refinement -- checking priority in general
  while_guard = (count_multisetindex < current_size);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Value() && count_mu_1_Value<3);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3);
  while ( while_guard )
    {
      oldcount_multisetindex = count_multisetindex;
      oldcount_mu_1_Value = count_mu_1_Value;
      oldcount_mu_1_Proc = count_mu_1_Proc;

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if ((!(*this)[k].mu_src.isundefined())
                && (*this)[k].mu_src>=1
                && (*this)[k].mu_src<=3)
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Proc; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_src.isundefined()
                          && (*this)[k].mu_src>=1
                          && (*this)[k].mu_src<=3
                          && pos_mu_1_Proc[j][(*this)[k].mu_src-1])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Proc[(*this)[k].mu_src-1] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Proc[j][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j][k] = FALSE;
                                if (pos_mu_1_Proc[j+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[j+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                      }
                  }
            }
        }

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      if ( ( count_multisetindex<current_size)
           || ( Perm.MTO_class_mu_1_Value() && count_mu_1_Value<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<current_size; k++) // step through class
            if (!(*this)[k].mu_val.isundefined())
              split = TRUE;
          if (split)
            {
              for (i=0; i<count_multisetindex; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Value; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<current_size; k++) // initialize goodset
                      goodset_multisetindex[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Value[k] = FALSE;
                    for (k=0; k<current_size; k++) // scan array index
                      // set goodsets
                      if (pos_multisetindex[i][k] 
                          && !(*this)[k].mu_val.isundefined()
                          && pos_mu_1_Value[j][(*this)[k].mu_val-4])
                        {
                          exists = TRUE;
                          goodset_multisetindex[k] = TRUE;
                          goodset_mu_1_Value[(*this)[k].mu_val-4] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<current_size; k++)
                          if ( pos_multisetindex[i][k] && !goodset_multisetindex[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_multisetindex; z>i; z--)
                              for (k=0; k<current_size; k++)
                                pos_multisetindex[z][k] = pos_multisetindex[z-1][k];
                            // split pos
                            for (k=0; k<current_size; k++)
                              {
                                if (pos_multisetindex[i][k] && !goodset_multisetindex[k])
                                  pos_multisetindex[i][k] = FALSE;
                                if (pos_multisetindex[i+1][k] && goodset_multisetindex[k])
                                  pos_multisetindex[i+1][k] = FALSE;
                              }
                            count_multisetindex++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Value; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Value[z][k] = pos_mu_1_Value[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j][k] = FALSE;
                                if (pos_mu_1_Value[j+1][k] && goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j+1][k] = FALSE;
                              }
                            count_mu_1_Value++;
                          }
                      }
                  }
            }
        }
      while_guard = oldcount_multisetindex!=count_multisetindex;
      while_guard = while_guard || (oldcount_mu_1_Value!=count_mu_1_Value);
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard_temp = while_guard;
      while_guard = (count_multisetindex < current_size);
      while_guard = while_guard || count_mu_1_Value<3;
      while_guard = while_guard || count_mu_1_Proc<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Value())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_Value[i][j])
            Perm.class_mu_1_Value[j] = i;
      Perm.undefined_class_mu_1_Value=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_Value[j]>Perm.undefined_class_mu_1_Value)
          Perm.undefined_class_mu_1_Value=Perm.class_mu_1_Value[j];
    }
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
  }
}
void mu_1__type_3::Permute(PermSet& Perm, int i)
{
  static mu_1__type_3 temp("Permute_mu_1__type_3",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=3; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Proc[Perm.in_mu_1_Proc[i]][j-1]];
};
void mu_1__type_3::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_3::Canonicalize(PermSet& Perm){};
void mu_1__type_3::SimpleLimit(PermSet& Perm){}
void mu_1__type_3::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_2 value[4];
  // limit
  bool exists;
  bool split;
  int count_mu_1_Proc;
  bool pos_mu_1_Proc[3][3];
  bool goodset_mu_1_Proc[3];
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<3; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<3; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
}
void mu_1__type_3::Limit(PermSet& Perm){}
void mu_1__type_3::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_4::Permute(PermSet& Perm, int i)
{
  static mu_1__type_4 temp("Permute_mu_1__type_4",-1);
  int j;
  for (j=0; j<3; j++)
    array[j].Permute(Perm, i);
};
void mu_1__type_4::SimpleCanonicalize(PermSet& Perm)
{
  for (int j=0; j<3; j++)
    array[j].SimpleCanonicalize(Perm);
}
void mu_1__type_4::Canonicalize(PermSet& Perm){};
void mu_1__type_4::SimpleLimit(PermSet& Perm)
{
  for (int j=0; j<3; j++) {
    array[j].SimpleLimit(Perm);
  }
}
void mu_1__type_4::ArrayLimit(PermSet& Perm) {}
void mu_1__type_4::Limit(PermSet& Perm){}
void mu_1__type_4::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };
void mu_1__type_5::Permute(PermSet& Perm, int i)
{
  static mu_1__type_5 temp("Permute_mu_1__type_5",-1);
  int j;
  for (j=0; j<4; j++)
    array[j].Permute(Perm, i);
  temp = *this;
  for (j=1; j<=3; j++)
    (*this)[j] = temp[Perm.revperm_mu_1_Proc[Perm.in_mu_1_Proc[i]][j-1]];
};
void mu_1__type_5::SimpleCanonicalize(PermSet& Perm)
{ Error.Error("Internal: Simple Canonicalization of Scalarset Array\n"); };
void mu_1__type_5::Canonicalize(PermSet& Perm){};
void mu_1__type_5::SimpleLimit(PermSet& Perm){}
void mu_1__type_5::ArrayLimit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // sorting
  int compare;
  static mu_1__type_4 value[4];
  // limit
  bool exists;
  bool split;
  int count_mu_1_Proc;
  bool pos_mu_1_Proc[3][3];
  bool goodset_mu_1_Proc[3];
  // sorting mu_1_Proc
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          pos_mu_1_Proc[i][j]=FALSE;
      count_mu_1_Proc = 0;
      for (i=0; i<3; i++)
        {
          for (j=0; j<count_mu_1_Proc; j++)
            {
              compare = CompareWeight(value[j],(*this)[i+1]);
              if (compare==0)
                {
                  pos_mu_1_Proc[j][i]= TRUE;
                  break;
                }
              else if (compare>0)
                {
                  for (k=count_mu_1_Proc; k>j; k--)
                    {
                      value[k] = value[k-1];
                      for (z=0; z<3; z++)
                        pos_mu_1_Proc[k][z] = pos_mu_1_Proc[k-1][z];
                    }
                  value[j] = (*this)[i+1];
                  for (z=0; z<3; z++)
                    pos_mu_1_Proc[j][z] = FALSE;
                  pos_mu_1_Proc[j][i] = TRUE;
                  count_mu_1_Proc++;
                  break;
                }
            }
          if (j==count_mu_1_Proc)
            {
              value[j] = (*this)[i+1];
              for (z=0; z<3; z++)
                pos_mu_1_Proc[j][z] = FALSE;
              pos_mu_1_Proc[j][i] = TRUE;
              count_mu_1_Proc++;
            }
        }
    }
  // if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc>1)
    {
      // limit
      for (j=0; j<3; j++) // class priority
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Proc[i][k] && Perm.class_mu_1_Proc[k] == j)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                    pos_mu_1_Proc[i][k] = FALSE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) 
                      split= TRUE;
                  if (split)
                    {
                      for (k=0; k<3; k++)
                        if (Perm.class_mu_1_Proc[k]>j
                            || ( Perm.class_mu_1_Proc[k] == j && !goodset_mu_1_Proc[k] ) )
                          Perm.class_mu_1_Proc[k]++;
                      Perm.undefined_class_mu_1_Proc++;
                    }
                }
            }
        }
    }
}
void mu_1__type_5::Limit(PermSet& Perm)
{
  // indexes
  int i,j,k,z;
  // while guard
  bool while_guard, while_guard_temp;
  // sorting
  static mu_1__type_4 value[4];
  // limit
  bool exists;
  bool split;
  int i0;
  int count_mu_1_Value, oldcount_mu_1_Value;
  bool pos_mu_1_Value[3][3];
  bool goodset_mu_1_Value[3];
  int count_mu_1_Proc, oldcount_mu_1_Proc;
  bool pos_mu_1_Proc[3][3];
  bool goodset_mu_1_Proc[3];
  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_Value[i][j]=FALSE;
  count_mu_1_Value = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_Value[i] == count_mu_1_Value)
         {
           pos_mu_1_Value[count_mu_1_Value][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Value++;
      else break;
    }
  // initializing pos array
  for (i=0; i<3; i++)
    for (j=0; j<3; j++)
      pos_mu_1_Proc[i][j]=FALSE;
  count_mu_1_Proc = 0;
  while (1)
    {
      exists = FALSE;
      for (i=0; i<3; i++)
       if (Perm.class_mu_1_Proc[i] == count_mu_1_Proc)
         {
           pos_mu_1_Proc[count_mu_1_Proc][i]=TRUE;
           exists = TRUE;
         }
      if (exists) count_mu_1_Proc++;
      else break;
    }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {

  // refinement -- check selfloop
  // only if there is more than 1 permutation in class
  if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
    {
      exists = FALSE;
      split = FALSE;
      // if there exists both self loop and non-self loop
      for (k=0; k<3; k++) // step through class
        if ((*this)[k+1][i0].mu_src.isundefined()
            ||(*this)[k+1][i0].mu_src!=k+1)
          exists = TRUE;
        else
          split = TRUE;
      if (exists && split)
        {
          for (i=0; i<count_mu_1_Proc; i++) // for value priority
            {
              exists = FALSE;
              for (k=0; k<3; k++) // step through class
                goodset_mu_1_Proc[k] = FALSE;
              for (k=0; k<3; k++) // step through class
                if (pos_mu_1_Proc[i][k] 
                    && !(*this)[k+1][i0].mu_src.isundefined()
                    && (*this)[k+1][i0].mu_src==k+1)
                  {
                    exists = TRUE;
                    goodset_mu_1_Proc[k] = TRUE;
                  }
              if (exists)
                {
                  split=FALSE;
                  for (k=0; k<3; k++)
                    if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                          split= TRUE;
                  if (split)
                    {
                      for (j=count_mu_1_Proc; j>i; j--)
                        for (k=0; k<3; k++)
                          pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                      for (k=0; k<3; k++)
                        {
                          if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i][k] = FALSE;
                          if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                            pos_mu_1_Proc[i+1][k] = FALSE;
                        }
                      count_mu_1_Proc++; i++;
                    }
                }
            }
        }
    }
  }

  // refinement -- checking priority in general
  while_guard = FALSE;
  while_guard = while_guard || (Perm.MTO_class_mu_1_Value() && count_mu_1_Value<3);
  while_guard = while_guard || (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3);
  while ( while_guard )
    {
      oldcount_mu_1_Value = count_mu_1_Value;
      oldcount_mu_1_Proc = count_mu_1_Proc;
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {

      // refinement -- graph structure for a single scalarset
      //               as in array S1 of S1
      // only if there is more than 1 permutation in class
      if (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if (!(*this)[k+1][i0].mu_src.isundefined()
                &&(*this)[k+1][i0].mu_src!=k+1
                &&(*this)[k+1][i0].mu_src>=1
                &&(*this)[k+1][i0].mu_src<=3)
              exists = TRUE;
          if (exists)
            {
              for (i=0; i<count_mu_1_Proc; i++) // for value priority
                {
                  for (j=0; j<count_mu_1_Proc; j++) // for value priority
                    {
                      exists = FALSE;
                      for (k=0; k<3; k++) // step through class
                        goodset_mu_1_Proc[k] = FALSE;
                      for (k=0; k<3; k++) // step through class
                        if (pos_mu_1_Proc[i][k] 
                            && !(*this)[k+1][i0].mu_src.isundefined()
                            && (*this)[k+1][i0].mu_src!=k+1
                            && (*this)[k+1][i0].mu_src>=1
                            && (*this)[k+1][i0].mu_src<=3
                            && pos_mu_1_Proc[j][(*this)[k+1][i0].mu_src-1])
                          {
                            exists = TRUE;
                            goodset_mu_1_Proc[k] = TRUE;
                          }
                      if (exists)
                        {
                          split=FALSE;
                          for (k=0; k<3; k++)
                            if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] ) 
                              split= TRUE;
                          if (split)
                            {
                              for (j=count_mu_1_Proc; j>i; j--)
                                for (k=0; k<3; k++)
                                  pos_mu_1_Proc[j][k] = pos_mu_1_Proc[j-1][k];
                              for (k=0; k<3; k++)
                                {
                                  if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i][k] = FALSE;
                                  if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                    pos_mu_1_Proc[i+1][k] = FALSE;                  
                                }
                              count_mu_1_Proc++;
                            }
                        }
                    }
                }
            }
        }
  }
  // loop through elements of a array indexed by subrange
  for (i0 = 0; i0 <= 2; i0++)
  {

      // refinement -- graph structure for two scalarsets
      //               as in array S1 of S2
      // only if there is more than 1 permutation in class
      if ( (Perm.MTO_class_mu_1_Proc() && count_mu_1_Proc<3)
           || ( Perm.MTO_class_mu_1_Value() && count_mu_1_Value<3) )
        {
          exists = FALSE;
          split = FALSE;
          for (k=0; k<3; k++) // step through class
            if ((*this)[k+1][i0].mu_val.isundefined())
              exists = TRUE;
            else
              split = TRUE;
          if (exists && split)
            {
              for (i=0; i<count_mu_1_Proc; i++) // scan through array index priority
                for (j=0; j<count_mu_1_Value; j++) //scan through element priority
                  {
                    exists = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Proc[k] = FALSE;
                    for (k=0; k<3; k++) // initialize goodset
                      goodset_mu_1_Value[k] = FALSE;
                    for (k=0; k<3; k++) // scan array index
                      // set goodsets
                      if (pos_mu_1_Proc[i][k] 
                          && !(*this)[k+1][i0].mu_val.isundefined()
                          && pos_mu_1_Value[j][(*this)[k+1][i0].mu_val-4])
                        {
                          exists = TRUE;
                          goodset_mu_1_Proc[k] = TRUE;
                          goodset_mu_1_Value[(*this)[k+1][i0].mu_val-4] = TRUE;
                        }
                    if (exists)
                      {
                        // set split for the array index type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Proc; z>i; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Proc[z][k] = pos_mu_1_Proc[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Proc[i][k] && !goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i][k] = FALSE;
                                if (pos_mu_1_Proc[i+1][k] && goodset_mu_1_Proc[k])
                                  pos_mu_1_Proc[i+1][k] = FALSE;
                              }
                            count_mu_1_Proc++;
                          }
                        // set split for the element type
                        split=FALSE;
                        for (k=0; k<3; k++)
                          if ( pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k] )
                            split= TRUE;
                        if (split)
                          {
                            // move following pos entries down 1 step
                            for (z=count_mu_1_Value; z>j; z--)
                              for (k=0; k<3; k++)
                                pos_mu_1_Value[z][k] = pos_mu_1_Value[z-1][k];
                            // split pos
                            for (k=0; k<3; k++)
                              {
                                if (pos_mu_1_Value[j][k] && !goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j][k] = FALSE;
                                if (pos_mu_1_Value[j+1][k] && goodset_mu_1_Value[k])
                                  pos_mu_1_Value[j+1][k] = FALSE;
                              }
                            count_mu_1_Value++;
                          }
                      }
                  }
            }
        }
  }
      while_guard = FALSE;
      while_guard = while_guard || (oldcount_mu_1_Value!=count_mu_1_Value);
      while_guard = while_guard || (oldcount_mu_1_Proc!=count_mu_1_Proc);
      while_guard_temp = while_guard;
      while_guard = FALSE;
      while_guard = while_guard || count_mu_1_Value<3;
      while_guard = while_guard || count_mu_1_Proc<3;
      while_guard = while_guard && while_guard_temp;
    } // end while
  // enter the result into class
  if (Perm.MTO_class_mu_1_Value())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_Value[i][j])
            Perm.class_mu_1_Value[j] = i;
      Perm.undefined_class_mu_1_Value=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_Value[j]>Perm.undefined_class_mu_1_Value)
          Perm.undefined_class_mu_1_Value=Perm.class_mu_1_Value[j];
    }
  // enter the result into class
  if (Perm.MTO_class_mu_1_Proc())
    {
      for (i=0; i<3; i++)
        for (j=0; j<3; j++)
          if (pos_mu_1_Proc[i][j])
            Perm.class_mu_1_Proc[j] = i;
      Perm.undefined_class_mu_1_Proc=0;
      for (j=0; j<3; j++)
        if (Perm.class_mu_1_Proc[j]>Perm.undefined_class_mu_1_Proc)
          Perm.undefined_class_mu_1_Proc=Perm.class_mu_1_Proc[j];
    }
}
void mu_1__type_5::MultisetLimit(PermSet& Perm)
{ Error.Error("Internal: calling MultisetLimit for scalarset array.\n"); };

/********************
 Auxiliary function for error trace printing
 ********************/
bool match(state* ns, StatePtr p)
{
  int i;
  static PermSet Perm;
  static state temp;
  StateCopy(&temp, ns);
  if (args->symmetry_reduction.value)
    {
      if (  args->sym_alg.mode == argsym_alg::Exhaustive_Fast_Canonicalize
         || args->sym_alg.mode == argsym_alg::Heuristic_Fast_Canonicalize) {
        Perm.ResetToExplicit();
        for (i=0; i<Perm.count; i++)
          if (Perm.In(i))
            {
              if (ns != workingstate)
                  StateCopy(workingstate, ns);
              
              mu_msg_processed.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_msg_processed.MultisetSort();
              mu_SumV.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_SumV.MultisetSort();
              mu_LastWrite.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_LastWrite.MultisetSort();
              mu_L2.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_L2.MultisetSort();
              mu_InBox.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_InBox.MultisetSort();
              mu_L1.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_L1.MultisetSort();
              mu_Net.Permute(Perm,i);
              if (args->multiset_reduction.value)
                mu_Net.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
      else {
        Perm.ResetToSimple();
        Perm.SimpleToOne();
        if (ns != workingstate)
          StateCopy(workingstate, ns);

          mu_msg_processed.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_msg_processed.MultisetSort();
          mu_SumV.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_SumV.MultisetSort();
          mu_LastWrite.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_LastWrite.MultisetSort();
          mu_L2.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_L2.MultisetSort();
          mu_InBox.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_InBox.MultisetSort();
          mu_L1.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_L1.MultisetSort();
          mu_Net.Permute(Perm,0);
          if (args->multiset_reduction.value)
            mu_Net.MultisetSort();
        if (p.compare(workingstate)) {
          StateCopy(workingstate,&temp); return TRUE; }

        while (Perm.NextPermutation())
          {
            if (ns != workingstate)
              StateCopy(workingstate, ns);
              
              mu_msg_processed.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_msg_processed.MultisetSort();
              mu_SumV.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_SumV.MultisetSort();
              mu_LastWrite.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_LastWrite.MultisetSort();
              mu_L2.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_L2.MultisetSort();
              mu_InBox.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_InBox.MultisetSort();
              mu_L1.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_L1.MultisetSort();
              mu_Net.Permute(Perm,0);
              if (args->multiset_reduction.value)
                mu_Net.MultisetSort();
            if (p.compare(workingstate)) {
              StateCopy(workingstate,&temp); return TRUE; }
          }
        StateCopy(workingstate,&temp);
        return FALSE;
      }
    }
  if (!args->symmetry_reduction.value
      && args->multiset_reduction.value)
    {
      if (ns != workingstate)
          StateCopy(workingstate, ns);
      mu_msg_processed.MultisetSort();
      mu_SumV.MultisetSort();
      mu_LastWrite.MultisetSort();
      mu_L2.MultisetSort();
      mu_InBox.MultisetSort();
      mu_L1.MultisetSort();
      mu_Net.MultisetSort();
      if (p.compare(workingstate)) {
        StateCopy(workingstate,&temp); return TRUE; }
      StateCopy(workingstate,&temp);
      return FALSE;
    }
  return (p.compare(ns));
}

/********************
 Canonicalization by fast exhaustive generation of
 all permutations
 ********************/
void SymmetryClass::Exhaustive_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;
  Perm.ResetToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_msg_processed.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_msg_processed.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_SumV.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_SumV.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_LastWrite.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_LastWrite.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_L2.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_L2.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_InBox.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_InBox.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_L1.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_L1.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Net.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 ********************/
void SymmetryClass::Heuristic_Fast_Canonicalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_LastWrite.SimpleCanonicalize(Perm);

  mu_L2.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_L1.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_L1.Limit(Perm);
  }

  Perm.SimpleToExplicit();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_InBox.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_InBox.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_L1.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_L1.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

  StateCopy(&temp, workingstate);
  ResetBestResult();
  for (i=0; i<Perm.count; i++)
    if (Perm.In(i))
      {
        StateCopy(workingstate, &temp);
        mu_Net.Permute(Perm,i);
        if (args->multiset_reduction.value)
          mu_Net.MultisetSort();
        SetBestResult(i, workingstate);
      }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Canonicalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and fast exhaustive generation of
 all permutations for other variables
 and use less local memory
 ********************/
void SymmetryClass::Heuristic_Small_Mem_Canonicalize(state* s)
{
  unsigned long cycle;
  static state temp;

  Perm.ResetToSimple();

  mu_LastWrite.SimpleCanonicalize(Perm);

  mu_L2.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_L1.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_L1.Limit(Perm);
  }

  Perm.SimpleToOne();

  StateCopy(&temp, workingstate);
  ResetBestResult();
  mu_InBox.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_InBox.MultisetSort();
  mu_L1.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_L1.MultisetSort();
  mu_Net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Net.MultisetSort();
  BestPermutedState = *workingstate;
  BestInitialized = TRUE;

  cycle=1;
  while (Perm.NextPermutation())
    {
      if (args->perm_limit.value != 0
          && cycle++ >= args->perm_limit.value) break;
      StateCopy(workingstate, &temp);
      mu_InBox.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_InBox.MultisetSort();
      mu_L1.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_L1.MultisetSort();
      mu_Net.Permute(Perm,0);
      if (args->multiset_reduction.value)
        mu_Net.MultisetSort();
      switch (StateCmp(workingstate, &BestPermutedState)) {
      case -1:
        BestPermutedState = *workingstate;
        break;
      case 1:
        break;
      case 0:
        break;
      default:
        Error.Error("funny return value from StateCmp");
      }
    }
  StateCopy(workingstate, &BestPermutedState);

};

/********************
 Normalization by fast simple variable canonicalization,
 fast simple scalarset array canonicalization,
 fast restriction on permutation set with simple scalarset array of scalarset,
 and for all other variables, pick any remaining permutation
 ********************/
void SymmetryClass::Heuristic_Fast_Normalize(state* s)
{
  int i;
  static state temp;

  Perm.ResetToSimple();

  mu_LastWrite.SimpleCanonicalize(Perm);

  mu_L2.SimpleCanonicalize(Perm);

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_L1.ArrayLimit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_InBox.Limit(Perm);
  }

  if (Perm.MoreThanOneRemain()) {
    mu_L1.Limit(Perm);
  }

  Perm.SimpleToOne();

  mu_InBox.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_InBox.MultisetSort();

  mu_L1.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_L1.MultisetSort();

  mu_Net.Permute(Perm,0);
  if (args->multiset_reduction.value)
    mu_Net.MultisetSort();

};

/********************
  Include
 ********************/
#include "mu_epilog.inc"
