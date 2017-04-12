//only executes when document is ready 
document.addEventListener('DOMContentLoaded', function() {
  //identifies HTML elements in popup that will be used
  var form = document.getElementById('textField');
  var submitButton = document.getElementById('submitButton');
  //creates queryInfo object for query request on line 11
  var queryInfo = {
    active: true,
    currentWindow: true
  };
  //gets information from tab and injects JS onto webpage
  chrome.tabs.query(queryInfo, function(tabs) { 
    submitButton.addEventListener("click", function() {
      var newTitle = form.value; 
      chrome.tabs.executeScript({
        code: 'document.title=' + JSON.stringify(newTitle)
      });
    });
  });
});