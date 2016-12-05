#include <phpcpp.h>
#include <string>
#include <doubler.h>

using std::string;

class Doubler : public Php::Base
{
public:
  Doubler() = default;
  virtual ~Doubler() = default;

  static Php::Value int_number(Php::Parameters&);
  static Php::Value float_number(Php::Parameters&);
  static Php::Value str(Php::Parameters&);
};

Php::Value Doubler::int_number(Php::Parameters& params)
{
  return double_int((int32_t)params[0]);
}

Php::Value Doubler::float_number(Php::Parameters& params)
{
  return double_float((double)params[0]);
}

Php::Value Doubler::str(Php::Parameters& params)
{
  char* s = double_str((char*)params[0].rawValue());
  return string(s);
}

/**
 *  tell the compiler that the get_module is a pure C function
 */
extern "C" {

    /**
     *  Function that is called by PHP right after the PHP process
     *  has started, and that returns an address of an internal PHP
     *  strucure with all the details and features of your extension
     *
     *  @return void*   a pointer to an address that is understood by PHP
     */
    PHPCPP_EXPORT void *get_module()
    {
        // static(!) Php::Extension object that should stay in memory
        // for the entire duration of the process (that's why it's static)
        static Php::Extension extension("doubler", "1.0");

        // @todo    add your own functions, classes, namespaces to the extension
        Php::Class<Doubler> doubler("Doubler");
        doubler.method<&Doubler::int_number>("int_number", {
            Php::ByVal("x", Php::Type::Numeric)
          });
        doubler.method<&Doubler::float_number>("float_number", {
            Php::ByVal("x", Php::Type::Float)
          });
        doubler.method<&Doubler::str>("str", {
            Php::ByVal("x", Php::Type::String)
          });

        extension.add(std::move(doubler));

        // return the extension
        return extension;
    }
}
