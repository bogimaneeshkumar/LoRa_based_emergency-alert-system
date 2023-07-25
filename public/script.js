fetch("http://127.0.0.1:3000/page1")
  .then((response) => response.json())
  .then((jsonData) => {
    const jsonDisplay = document.getElementById("json-display");
    console.log(jsonDisplay);
    jsonDisplay.textContent = JSON.stringify(jsonData, null, 2);
    jsonDisplay.classList.add("active");
  });
