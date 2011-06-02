var eventName,numGuests,costPerGuest,numLimos,costPerLimo,maxCap,total,musicCost,flowersCost,barCost,music,flowers,openBar;
var limoTotal=0
var guestTotal=0;

eventName = "Wedding";

numGuests = 501;
costPerGuest = 250;
numLimos = 25;
costPerLimo = 100;

musicCost = 500;
flowersCost = 300;
barCost = 30;

music = true;
flowers = true;
openBar = true;

maxCap = 500;
total = 0;

limoTotal = numLimos*costPerLimo;
guestTotal = numGuests*costPerGuest;

if (music){
    total += musicCost;
}
if (flowers){
    total += flowersCost;
}
if (openBar){
    total += barCost*numGuests;
}

total += (limoTotal+guestTotal);

document.write("<p>Welcome to the wedding.</p><ul>");
document.write("<li>There are "+numGuests+" guests attending. At the price of $"+costPerGuest+" per guest, you will spend $"+guestTotal+" on people you don't really care for.</li>");
if (numGuests>maxCap){
    document.write("<li>(You have invited too many guests (max is 500))</li>");
}
document.write("<li>There are "+numLimos+ " limousines reserved at $"+costPerLimo+" per limousine. You will spend $"+limoTotal+" on transporation for those people you don't really care about.</li>");
document.write("<li>You also opted for live music. Wise choice, it only cost you an extra $"+musicCost+".</li>");
document.write("<li>Continuing in a similar vein of extravagance, you spent $"+flowersCost+" on flowers.</li>");
document.write("<li>Finally, you opted for an open bar, which cost $"+barCost+" per guest...which brings your alcohol tab up to $"+(barCost*numGuests)+".</li>");
document.write("<li>Congratulations, selling your future for minor tax considerations only cost you $"+total+"!</li></ul>");

