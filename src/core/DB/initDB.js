// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: "AIzaSyDve2mKzoW1vFKVehtejnuxuaB1JhD0u0E",
  authDomain: "trabpds.firebaseapp.com",
  projectId: "trabpds",
  storageBucket: "trabpds.appspot.com",
  messagingSenderId: "316714555374",
  appId: "1:316714555374:web:5c14b71cb706a4008fa0ff",
  measurementId: "G-JDYH29RHL8"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);
const analytics = getAnalytics(app);