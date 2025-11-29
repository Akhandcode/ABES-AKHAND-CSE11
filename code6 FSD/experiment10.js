// Load saved tasks on page load
loadTasks();

// Add Task Function
function addTask() {
    let input = document.getElementById("taskInput");
    let taskText = input.value.trim();

    if (taskText === "") {
        alert("Enter a task!");
        return;
    }

    createTask(taskText);
    saveTasks();
    input.value = "";
    updateCount();
}

// Create Task Function (UI + Buttons)
function createTask(taskText, completed = false) {
    let ul = document.getElementById("taskList");

    let li = document.createElement("li");
    li.textContent = taskText;
    if (completed) li.classList.add("completed");

    let btnDiv = document.createElement("div");
    btnDiv.className = "task-buttons";

    // ✔ Done Button
    let done = document.createElement("button");
    done.textContent = "✔";
    done.className = "doneBtn";
    done.onclick = () => {
        li.classList.toggle("completed");
        saveTasks();
    };

    // ✎ Edit Button
    let edit = document.createElement("button");
    edit.textContent = "✎";
    edit.className = "editBtn";
    edit.onclick = () => {
        let newText = prompt("Edit task:", li.firstChild.textContent);
        if (newText !== null && newText.trim() !== "") {
            li.firstChild.textContent = newText.trim();
            saveTasks();
        }
    };

    // 🗑 Delete Button
    let del = document.createElement("button");
    del.textContent = "🗑";
    del.className = "delBtn";
    del.onclick = () => {
        li.remove();
        saveTasks();
        updateCount();
    };

    btnDiv.appendChild(done);
    btnDiv.appendChild(edit);
    btnDiv.appendChild(del);

    li.appendChild(btnDiv);
    ul.appendChild(li);
}

// Save all tasks to localStorage
function saveTasks() {
    let tasks = [];
    document.querySelectorAll("#taskList li").forEach(li => {
        tasks.push({
            text: li.firstChild.textContent,
            completed: li.classList.contains("completed")
        });
    });
    localStorage.setItem("todoTasks", JSON.stringify(tasks));
    updateCount();
}

// Load saved tasks from localStorage
function loadTasks() {
    let saved = localStorage.getItem("todoTasks");
    if (saved) {
        JSON.parse(saved).forEach(task => createTask(task.text, task.completed));
    }
    updateCount();
}

// Clear All Tasks
function clearAll() {
    if (confirm("Are you sure you want to delete all tasks?")) {
        document.getElementById("taskList").innerHTML = "";
        saveTasks();
        updateCount();
    }
}a

// Update Task Counter
function updateCount() {
    let total = document.querySelectorAll("#taskList li").length;
    document.getElementById("taskCount").textContent = total;
}
