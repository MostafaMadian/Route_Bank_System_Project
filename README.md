# Route Bank — Live Demo

This folder contains a browser demo based on the supplied C++ Route Bank project.

## Important distinction

The original application is a Windows console C++ application. It uses `windows.h`, `Sleep`, `system("cls")`, Windows console APIs, and local text files. It therefore cannot be uploaded to GitHub Pages and executed unchanged in a browser.

`index.html` is a browser-compatible demo that preserves the main user flows and business rules:
- Admin / Employee / Client login
- Balance check
- Deposit / Withdraw / Transfer
- Password editing
- Client / Employee management
- Search and listing
- Validation rules
- Persistent demo data with browser localStorage

The original C++ project should remain the source-code reference in the GitHub repository.

## Demo accounts

- Admin: ID `1`, Password `Admin1234`
- Employee: ID `1`, Password `Employee123`
- Client: ID `1`, Password `Client1234`

These are demo-only credentials. Do not publish real credentials from the original text files.

## Deploy with GitHub Pages

1. Create a GitHub repository.
2. Put `index.html` in the repository root.
3. Open repository Settings → Pages.
4. Select GitHub Actions or deploy from the `main` branch/root.
5. GitHub will provide the public Pages URL.

You can then place that URL beside the repository link on the course page:
- **Try Live Demo**
- **View C++ Source Code**

## Note

This demo is intentionally client-side and educational. It is not a real banking application and has no server-side authentication or security.
