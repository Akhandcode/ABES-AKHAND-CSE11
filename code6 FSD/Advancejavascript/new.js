let user={
    name:"divang",
    age:37,
    address:{
        city:"dehli",
        pincode:1101,
    }
};
let usercopy=JSON.parse(JSON.stringify(user));
usercopy.address.city=
 