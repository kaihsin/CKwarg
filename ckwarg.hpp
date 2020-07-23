#ifndef _H_CKWARG_
#define _H_CKWARG_

#include <boost/hana.hpp>

using namespace boost::hana::literals;

// for using (""_arg = sth.) -> boost::hana::make_pair()
template<char... Chars>
struct named_param{
    using name = boost::hana::string<Chars...>;
    constexpr auto get_name() const {return name{};}
    
    template<typename T>
    constexpr auto operator=(T&& value){
        return boost::hana::make_pair(get_name(),std::forward<T>(value));
    }
};

// define literal for keywords
template<typename CharT, CharT... Chars>
constexpr auto operator"" _arg() -> named_param<Chars...>{
    return{};
}

// constexpr lambda, with auto.
constexpr auto get_names = [](auto arg_spec){
    return boost::hana::transform(arg_spec,[](auto key){
        return key.get_name();
    });
};

constexpr auto extract(auto arg_spec,auto args){
    return boost::hana::transform(arg_spec, [args](auto key){
            return args[key];
    });  
};

constexpr auto adapt = [](auto &f, auto... input_arg_spec){
    auto arg_spec = boost::hana::make_tuple(input_arg_spec...);
    auto arg_names = get_names(arg_spec);
    // return a lambda
    return [&f,arg_names](auto... input_arg_spec){
        auto args = boost::hana::make_map(input_arg_spec...);
        auto arg_pack = extract(arg_names,args);
        return boost::hana::unpack(arg_pack,f);
    };
};

#endif
