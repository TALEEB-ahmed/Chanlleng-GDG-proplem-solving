#!/bin/bash
set -e

npm create vite@latest . -- --template react

npm install
npm install tailwindcss @tailwindcss/vite

cat > vite.config.js <<'EOF'
import { defineConfig } from 'vite'
import react from '@vitejs/plugin-react'
import tailwindcss from '@tailwindcss/vite'

export default defineConfig({
  plugins: [react(), tailwindcss()],
})
EOF

echo '@import "tailwindcss";' > src/index.css

npm run dev -- --host 0.0.0.0
