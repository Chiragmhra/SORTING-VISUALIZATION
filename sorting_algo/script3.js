let array = [];
const container = document.getElementById("array-container");
const icon = document.getElementById("icon");
const explanation = document.getElementById("explanation");

function createArray() {
  container.innerHTML = "";
  icon.style.display = "none";
  explanation.innerHTML = "Array created. Choose algorithm and start sorting.";
  array = document.getElementById("arrayInput").value
    .split(",")
    .map(num => parseInt(num.trim()))
    .filter(num => !isNaN(num));

  array.forEach((value, index) => {
    const box = document.createElement("div");
    box.classList.add("box");
    box.textContent = value;
    box.dataset.index = index;
    container.appendChild(box);
  });
}

function sleep(ms) {
  return new Promise(resolve => setTimeout(resolve, ms));
}

function updateExplanation(text) {
  explanation.innerHTML = text;
}

// Move icon near boxes
function moveIcon(box) {
  const rect = box.getBoundingClientRect();
  const containerRect = container.getBoundingClientRect();
  icon.style.display = "block";
  icon.style.left = `${box.offsetLeft + 25}px`;
  icon.style.top = `${box.offsetTop + containerRect.top - 100}px`;
}

// Swap helper
async function swapBoxes(i, j) {
  const boxes = document.getElementsByClassName("box");
  moveIcon(boxes[i]);
  boxes[i].classList.add("active");
  boxes[j].classList.add("active");

  await sleep(800);

  let temp = array[i];
  array[i] = array[j];
  array[j] = temp;

  boxes[i].textContent = array[i];
  boxes[j].textContent = array[j];

  await sleep(800);

  boxes[i].classList.remove("active");
  boxes[j].classList.remove("active");
}

async function startSort() {
  const algo = document.getElementById("algorithm").value;
  if (algo === "bubble") await bubbleSort();
  if (algo === "insertion") await insertionSort();
  if (algo === "selection") await selectionSort();
}

// 🔹 Bubble Sort
async function bubbleSort() {
  const boxes = document.getElementsByClassName("box");
  updateExplanation("🔹 Bubble Sort: Compare adjacent elements and swap if needed.");

  for (let i = 0; i < array.length; i++) {
    for (let j = 0; j < array.length - i - 1; j++) {
      updateExplanation(`Comparing ${array[j]} and ${array[j + 1]}`);
      moveIcon(boxes[j]);
      await sleep(500);
      if (array[j] > array[j + 1]) {
        await swapBoxes(j, j + 1);
      }
    }
    boxes[array.length - i - 1].classList.add("sorted");
  }
  updateExplanation("✅ Bubble Sort completed!");
}

// 🔹 Insertion Sort
async function insertionSort() {
  const boxes = document.getElementsByClassName("box");
  updateExplanation("🔹 Insertion Sort: Insert each element in its correct place.");

  for (let i = 1; i < array.length; i++) {
    let j = i;
    updateExplanation(`Inserting ${array[i]} in sorted part.`);
    moveIcon(boxes[i]);
    await sleep(500);
    while (j > 0 && array[j - 1] > array[j]) {
      await swapBoxes(j, j - 1);
      j--;
    }
  }

  for (let k = 0; k < array.length; k++) {
    boxes[k].classList.add("sorted");
  }
  updateExplanation("✅ Insertion Sort completed!");
}

// 🔹 Selection Sort
async function selectionSort() {
  const boxes = document.getElementsByClassName("box");
  updateExplanation("🔹 Selection Sort: Find min and place at correct position.");

  for (let i = 0; i < array.length; i++) {
    let minIndex = i;
    for (let j = i + 1; j < array.length; j++) {
      moveIcon(boxes[j]);
      await sleep(500);
      if (array[j] < array[minIndex]) {
        minIndex = j;
      }
    }
    if (minIndex !== i) {
      updateExplanation(`Swapping ${array[i]} and ${array[minIndex]}`);
      await swapBoxes(i, minIndex);
    }
    boxes[i].classList.add("sorted");
  }
  updateExplanation("✅ Selection Sort completed!");
}