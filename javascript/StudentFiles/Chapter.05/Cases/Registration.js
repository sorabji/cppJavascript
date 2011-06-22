function clearMe(formfield){
    if (formfield.defaultValue==formfield.value)
    formfield.value = ""
 }

function isNumberKey(evt){
    var charCode = (evt.which) ? evt.which : event.keyCode

    if (charCode > 31 && (charCode < 48 || charCode > 57)){
        return false;
    }
    return true;
} 

function validateForm(){
    var pass1 = document.getElementById("password").value;
    var pass2 = document.getElementById("confirmPass").value;
    var firstName = document.getElementById("firstName").value;
    var lastName = document.getElementById("lastName").value;
    var email = document.getElementById("email").value;
    var areaCode = document.getElementById("areaCode").value;
    var phone1 = document.getElementById("phone1").value;
    var phone2 = document.getElementById("phone2").value;
    var securityQuestion = document.getElementById("securityQuestion").value;
    var radioButtons = document.forms["RegistrationForm"].specialOffers;
    var checkBoxes = document.forms["RegistrationForm"].interests;
//interests (radio boxes)

    if(!matchPasswords(pass1,pass2)) return false;

    if(firstName == "enter your first name"){
        alert("enter your first name please");
        return false;
    }
    
    if(lastName == "enter your last name"){
        alert("enter your last name please");
        return false;
    }

    if(!email || !areaCode || !phone1 || !phone2 || !securityQuestion) return false;

    if(checkForSelectedRadio(radioButtons)<0){
        alert("you must decide whether or not you want to be spammed by offers!");
        return false;
    }

    if(getSelectedCheckboxes(checkBoxes).length<1){
        alert("you must be interested in at least one thing!");
        return false;
    }

}

function matchPasswords(password1,password2){
    if (password1 == "" || password2 == ""){
        alert("your must enter and confirm your password");
        return false;
    }

    if (password1 && password2){
        if (password1.search(password2)==0){
            alert("passwords match!");
            return true;
        }
    }
    alert("passwords do not match");
    return false;
}

function checkForSelectedRadio(radios){
   if (radios[0]){ 
      for (var i=0; i<radios.length; i++){
         if (radios[i].checked){
            return i
         }
      }
   }
   else{
      if (radios.checked){
          return 0;
      } 
   }

   return -1;
}

function getSelectedCheckboxes(checkArray) {
   var returnArray = new Array();
   var j = 0;

   for (var i=0; i<checkArray.length; i++) {
      if (checkArray[i].checked) {
         returnArray.length = j;
         returnArray[j] = i;
         j++;
      }
   }
   return returnArray;
}
