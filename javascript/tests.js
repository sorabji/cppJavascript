function processCourses(){
    var courseList="";
    var coursesfall=document.dataform.coursesfall;
    var coursesspring=document.dataform.coursesspring;
    var fallcourse;
    var springcourse;
    var modsenrolled="";
    for (var i=0;i<coursesfall.length;i++){
	    if(coursesfall[i].checked==true){
	        courseList+=coursesfall[i].value+"</br>";
	        fallcourse=coursesfall[i].value;
	    }
    }

    for (var i=0;i<coursesspring.length;i++){
	    if(coursesspring[i].checked==true){
	        courseList+=coursesspring[i].value+"</br>";
	        springcourse=coursesspring[i].value;
	    }
    }

    if(fallcourse==springcourse){
	    document.getElementById("courseList").innerHTML="You have selected "+fallcourse+" in both terms";
	    return false;
    }

    var modenrollment=document.dataform.modenrollment;

    for(var i=0;i<modenrollment.length;i++){
	    if(modenrollment[i].checked){
	        modsenrolled+=modenrollment[i].value+"</br>";
	    }
    }

    //alert("modsenrolled " + modsenrolled);
    document.getElementById("courseList").innerHTML="The courses you have selected are </br>" 
        + courseList + ".</br>You are enrolled in the following mods: </br>" + modsenrolled;
    return false;
}
